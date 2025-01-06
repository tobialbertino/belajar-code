fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod test {
    use futures::TryStreamExt;
    use sqlx::postgres::{PgPoolOptions, PgRow};
    use sqlx::{Connection, Error, PgConnection, Pool, Postgres, Row};

    #[tokio::test]
    async fn test_fetch() -> Result<(), Error> {
        let pool = get_pool().await?;

        let mut result = sqlx::query("SELECT * FROM category").fetch(&pool);

        while let Some(row) = result.try_next().await? {
            let id: String = row.get("id");
            let name: String = row.get("name");
            let description: String = row.get("description");
            println!(
                "id : {}, name : {}, description : {}",
                id, name, description
            );
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_fetch_all() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: Vec<PgRow> = sqlx::query("SELECT * FROM category")
            .fetch_all(&pool)
            .await?;

        for row in result {
            let id: String = row.get("id");
            let name: String = row.get("name");
            let description: String = row.get("description");
            println!(
                "id : {}, name : {}, description : {}",
                id, name, description
            );
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_fetch_one() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: PgRow = sqlx::query("SELECT * FROM category WHERE id = $1")
            .bind("A")
            .fetch_one(&pool)
            .await?;

        let id: String = result.get("id");
        let name: String = result.get("name");
        let description: String = result.get("description");
        println!(
            "id : {}, name : {}, description : {}",
            id, name, description
        );

        Ok(())
    }

    #[tokio::test]
    async fn test_fetch_optional() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: Option<PgRow> = sqlx::query("SELECT * FROM category WHERE id = $1")
            .bind("A")
            .fetch_optional(&pool)
            .await?;

        if let Some(row) = result {
            let id: String = row.get("id");
            let name: String = row.get("name");
            let description: String = row.get("description");
            println!(
                "id : {}, name : {}, description : {}",
                id, name, description
            )
        } else {
            print!("data is not found")
        }
        Ok(())
    }

    #[tokio::test]
    async fn test_prepare_statement() -> Result<(), Error> {
        let pool = get_pool().await?;
        sqlx::query("INSERT INTO category (id, name, description) VALUES ($1, $2, $3)")
            .bind("B")
            .bind("contoh lagi")
            .bind("contoh deskripsi")
            .execute(&pool)
            .await?;
        Ok(())
    }

    #[tokio::test]
    async fn test_execute() -> Result<(), Error> {
        let pool = get_pool().await?;
        sqlx::query(
            "INSERT INTO category (id, name, description) VALUES ('A', 'contoh', 'contoh')",
        )
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
    async fn test_manual_connection() -> Result<(), Error> {
        let url = "postgres://postgres:postgres@localhost:5432/belajar_rust_database";
        let connection = PgConnection::connect(url).await?;

        connection.close().await?;
        Ok(())
    }
}
