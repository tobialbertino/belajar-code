fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod tests {
    use redis::aio::MultiplexedConnection;
    use redis::{AsyncCommands, Client, Commands, RedisError};
    use std::time::Duration;

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
