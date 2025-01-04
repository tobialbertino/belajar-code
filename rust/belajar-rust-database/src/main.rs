fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod test {
    use sqlx::{Connection, Error, PgConnection};

    #[tokio::test]
    async fn test_manual_connection() -> Result<(), Error>{
        let url = "postgres://postgres:postgres@localhost:5432/belajar_rust_database";
        let connection = PgConnection::connect(url).await?;

        connection.close().await?;
        Ok(())
    }
}