fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use std::num::NonZero;
    use redis::aio::MultiplexedConnection;
    use redis::{AsyncCommands, Client, Commands, RedisError};
    use std::time::Duration;

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

        let lists: Vec<String> = con.lpop("list",NonZero::new(1)).await?;
        assert_eq!(vec!["value1"], lists);
        let lists: Vec<String> = con.lpop("list",NonZero::new(1)).await?;
        assert_eq!(vec!["value2"], lists);
        let lists: Vec<String> = con.lpop("list",NonZero::new(1)).await?;
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
