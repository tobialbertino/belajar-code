fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use futures::StreamExt;
    use redis::aio::{MultiplexedConnection, PubSub};
    use redis::geo::{RadiusOptions, Unit};
    use redis::streams::{StreamReadOptions, StreamReadReply};
    use redis::{AsyncCommands, Client, Commands, RedisError, Value};
    use std::collections::HashMap;
    use std::num::NonZero;
    use std::time::Duration;

    async fn get_pubsub() -> Result<PubSub, RedisError> {
        let client = Client::open("redis://localhost:6379/")?;
        client.get_async_pubsub().await
    }

    #[tokio::test]
    async fn test_pubsub_publish() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        let _: () = con.publish("channel", "message").await?;
        Ok(())
    }

    #[tokio::test]
    async fn test_pubsub_subscriber() -> Result<(), RedisError> {
        let mut pubsub = get_pubsub().await?;

        let _: () = pubsub.subscribe("channel").await?;
        let mut pubsub_stream = pubsub.on_message();

        let message: String = pubsub_stream.next().await.unwrap().get_payload()?;
        println!("Message: {}", message);

        Ok(())
    }

    #[tokio::test]
    async fn test_create_stream() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        let setting = StreamReadOptions::default()
            .group("group-1", "consumer1")
            .count(5)
            .block(3000);

        let result: StreamReadReply = con.xread_options(&["stream"], &[">"], &setting).await?;

        for key in result.keys {
            for item in key.ids {
                let map: HashMap<String, Value> = item.map;
                let name: String = match map.get("name").unwrap() {
                    Value::BulkString(value) => String::from_utf8(value.to_vec())?,
                    _ => "".to_string(),
                };
                let address: String = match map.get("address").unwrap() {
                    Value::BulkString(value) => String::from_utf8(value.to_vec())?,
                    _ => "".to_string(),
                };

                println!("Name: {}, Address: {}", name, address);
            }
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_create_consumer() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        let _: () = con.xgroup_create("stream", "group-1", "0").await?;
        let _: () = con
            .xgroup_createconsumer("stream", "group-1", "consumer1")
            .await?;
        let _: () = con
            .xgroup_createconsumer("stream", "group-1", "consumer2")
            .await?;

        Ok(())
    }

    #[tokio::test]
    async fn test_publish_stream() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        for i in 0..10 {
            let mut map: HashMap<String, String> = HashMap::new();
            map.insert("name".to_string(), format!("name{}", i));
            map.insert("address".to_string(), "address".to_string());

            let _: () = con.xadd_map("stream", "*", &map).await?;
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_transaction() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        redis::pipe()
            .atomic()
            .set_ex("key1", "value1", 10)
            .set_ex("key2", "value2", 10)
            // other operation
            .exec_async(&mut con)
            .await?;

        let value1: String = con.get("key1").await?;
        let value2: String = con.get("key2").await?;
        assert_eq!("value1", value1);
        assert_eq!("value2", value2);

        Ok(())
    }

    #[tokio::test]
    async fn test_pipeline() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        redis::pipe()
            .set_ex("key1", "value1", 10)
            .set_ex("key2", "value2", 10)
            // other operation
            .exec_async(&mut con)
            .await?;

        let value1: String = con.get("key1").await?;
        let value2: String = con.get("key2").await?;
        assert_eq!("value1", value1);
        assert_eq!("value2", value2);

        Ok(())
    }

    #[tokio::test]
    async fn test_hyper_log_log() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        // count unique elements
        let _: () = con.pfadd("hll", ("a", "b")).await?;
        let _: () = con.pfadd("hll", ("b", "a")).await?;
        let _: () = con.pfadd("hll", ("c", "d")).await?;

        let count: i64 = con.pfcount("hll").await?;
        assert_eq!(4, count);

        Ok(())
    }

    #[tokio::test]
    async fn test_geo_point() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        let _: () = con.geo_add("geo", (1.0, 1.0, "point1")).await?;
        let _: () = con.geo_add("geo", (2.0, 2.0, "point2")).await?;

        let distance: f64 = con
            .geo_dist("geo", "point1", "point2", Unit::Kilometers)
            .await?;
        assert_eq!(157.2701, distance);

        let result: Vec<String> = con
            .geo_radius(
                "geo",
                1.0,
                1.0,
                2000.0,
                Unit::Kilometers,
                RadiusOptions::default(),
            )
            .await?;
        assert_eq!(vec!["point1", "point2"], result);

        Ok(())
    }

    #[tokio::test]
    async fn test_hash() -> Result<(), RedisError> {
        let mut con = get_client().await?;

        let _: () = con.hset("hash", "field1", "value1").await?;
        let _: () = con.hset("hash", "field2", "value2").await?;
        let _: () = con.hset("hash", "field3", "value3").await?;

        let len: i32 = con.hlen("hash").await?;
        assert_eq!(3, len);

        let hash: HashMap<String, String> = con.hgetall("hash").await?;
        assert_eq!(3, hash.len());
        assert_eq!("value1", hash.get("field1").unwrap());
        assert_eq!("value2", hash.get("field2").unwrap());
        assert_eq!("value3", hash.get("field3").unwrap());
        Ok(())
    }

    #[tokio::test]
    async fn test_sorted_set() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        let _: () = con.zadd("sorted_set", "value1", 100).await?;
        let _: () = con.zadd("sorted_set", "value2", 90).await?;
        let _: () = con.zadd("sorted_set", "value3", 80).await?;
        // sorted set is sorted by score

        let len: i32 = con.zcard("sorted_set").await?;
        assert_eq!(3, len);

        let sets: Vec<String> = con.zrange("sorted_set", 0, -1).await?;
        assert_eq!(vec!["value3", "value2", "value1"], sets);

        Ok(())
    }

    #[tokio::test]
    async fn test_set() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        let _: () = con.sadd("set", "value1").await?; // always unique
        let _: () = con.sadd("set", "value1").await?;
        let _: () = con.sadd("set", "value2").await?;
        let _: () = con.sadd("set", "value2").await?;
        let _: () = con.sadd("set", "value3").await?;
        let _: () = con.sadd("set", "value3").await?;

        let len: i32 = con.scard("set").await?;
        assert_eq!(3, len);

        let sets: Vec<String> = con.smembers("set").await?;
        assert_eq!(vec!["value1", "value2", "value3"], sets);

        Ok(())
    }

    #[tokio::test]
    async fn test_list() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        let _: () = con.rpush("list", "value1").await?;
        let _: () = con.rpush("list", "value2").await?;
        let _: () = con.rpush("list", "value3").await?;

        let len: i32 = con.llen("list").await?;
        assert_eq!(3, len);

        let lists: Vec<String> = con.lrange("list", 0, -1).await?; // -1 means all elements
        assert_eq!(vec!["value1", "value2", "value3"], lists);

        let lists: Vec<String> = con.lpop("list", NonZero::new(1)).await?;
        assert_eq!(vec!["value1"], lists);
        let lists: Vec<String> = con.lpop("list", NonZero::new(1)).await?;
        assert_eq!(vec!["value2"], lists);
        let lists: Vec<String> = con.lpop("list", NonZero::new(1)).await?;
        assert_eq!(vec!["value3"], lists);

        Ok(())
    }

    #[tokio::test]
    async fn test_string() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        let _: () = con.set_ex("key", "value", 2).await?;
        let result: String = con.get("key").await?;
        println!("Result: {}", result);

        tokio::time::sleep(Duration::from_secs(5)).await;
        let value: Result<String, RedisError> = con.get("key").await;
        assert_eq!(true, value.is_err());

        Ok(())
    }

    #[tokio::test]
    async fn test_async_connection() -> Result<(), RedisError> {
        let mut con = get_client().await?;
        con.set_ex::<&str, &str, ()>("key", "value", 10).await?;
        let result: String = con.get("key").await?;

        println!("Result: {}", result);

        Ok(())
    }

    async fn get_client() -> Result<MultiplexedConnection, RedisError> {
        let client = Client::open("redis://localhost:6379/")?;
        client.get_multiplexed_async_connection().await
    }

    #[test]
    fn test_connection() {
        let mut client = Client::open("redis://localhost:6379/0").unwrap();

        client.set_ex::<&str, &str, ()>("key", "value", 10).unwrap();
        let value: String = client.get("key").unwrap();
        println!("Value: {}", value);
    }
}
