fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod test {
    use sqlx::{Connection, Error, PgConnection, Pool, Postgres};
    use sqlx::postgres::PgPoolOptions;

    #[tokio::test]
    async fn test_execute() -> Result<(), Error> {
        let pool = get_pool().await?;
        sqlx::query("INSERT INTO category (id, name, description) VALUES ('A', 'contoh', 'contoh')")
            .execute(&pool)
            .await?;
        Ok(())
    }


    #[tokio::test]
    async fn test_pool_connection() -> Result<(), Error> {
        let pool = get_pool().await?;
        pool.close().await;
        Ok(())
    }

    async fn get_pool() -> Result<Pool<Postgres>, Error> {
        let url = "postgres://postgres:postgres@localhost:5432/belajar_rust_database";
        PgPoolOptions::new()
            .max_connections(10)
            .min_connections(5)
            .acquire_timeout(std::time::Duration::from_secs(5))
            .idle_timeout(std::time::Duration::from_secs(60))
            .connect(url)
            .await
    }

    #[tokio::test]
    async fn test_manual_connection() -> Result<(), Error>{
        let url = "postgres://postgres:postgres@localhost:5432/belajar_rust_database";
        let connection = PgConnection::connect(url).await?;

        connection.close().await?;
        Ok(())
    } 

}