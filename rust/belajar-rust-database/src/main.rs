fn main() {
    println!("Hello, world!");
}

#[cfg(test)]
mod test {
    use chrono::Local;
    use futures::TryStreamExt;
    use sqlx::postgres::{PgPoolOptions, PgRow};
    use sqlx::{Connection, Error, FromRow, PgConnection, Pool, Postgres, Row};

    #[derive(Debug, FromRow)]
    struct Category {
        id: String,
        name: String,
        description: String,
    }

    #[derive(Debug, FromRow)]
    struct Brand {
        id: String,
        name: String,
        description: String,
        created_at: chrono::NaiveDateTime,
        updated_at: chrono::NaiveDateTime,
    }

    #[tokio::test]
    async fn test_auto_increment_with_transaction() -> Result<(), Error> {
        let pool = get_pool().await?;
        let mut transaction = pool.begin().await?;
        sqlx::query("INSERT INTO sellers (name) VALUES ($1) returning id")
            .bind("Contoh Seller")
            .execute(&mut *transaction).await?;

        let result: PgRow = sqlx::query("select lastval() as id")
            .fetch_one(&mut *transaction)
            .await?;

        let id: i32 = result.get_unchecked("id");
        println!("id seller: {}", id);
        Ok(())
    }

    #[tokio::test]
    async fn test_auto_increment() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: PgRow = sqlx::query("INSERT INTO sellers (name) VALUES ($1) returning id")
            .bind("Contoh Seller")
            .fetch_one(&pool).await?;

        let id: i32 = result.get("id");
        println!("id seller: {}", id);
        Ok(())
    }

    #[tokio::test]
    async fn test_transaction() -> Result<(), Error> {
        let pool = get_pool().await?;
        let mut transaction = pool.begin().await?;

        sqlx::query("INSERT INTO brands (id, name, description, created_at, updated_at) VALUES ($1, $2, $3, $4, $5)")
            .bind("B")
            .bind("contoh name")
            .bind("contoh deskripsi")
            .bind(Local::now().naive_local())
            .bind(Local::now().naive_local())
            .execute(&mut *transaction).await?;

        sqlx::query("INSERT INTO brands (id, name, description, created_at, updated_at) VALUES ($1, $2, $3, $4, $5)")
            .bind("C")
            .bind("contoh name")
            .bind("contoh deskripsi")
            .bind(Local::now().naive_local())
            .bind(Local::now().naive_local())
            .execute(&mut *transaction).await?;

        sqlx::query("INSERT INTO brands (id, name, description, created_at, updated_at) VALUES ($1, $2, $3, $4, $5)")
            .bind("D")
            .bind("contoh name")
            .bind("contoh deskripsi")
            .bind(Local::now().naive_local())
            .bind(Local::now().naive_local())
            .execute(&mut *transaction).await?;

        transaction.commit().await?;

        Ok(())
    }

    #[tokio::test]
    async fn test_result_mapping_brand() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: Vec<Brand> = sqlx::query_as("SELECT * FROM brands")
            .fetch_all(&pool)
            .await?;

        for brand in result {
            println!("{:?}", brand);
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_insert_brand() -> Result<(), Error> {
        let pool = get_pool().await?;

    sqlx::query("INSERT INTO brands (id, name, description, created_at, updated_at) VALUES ($1, $2, $3, $4, $5)")
        .bind("A")
        .bind("contoh name")
        .bind("contoh deskripsi")
        .bind(Local::now().naive_local())
        .bind(Local::now().naive_local())
        .execute(&pool).await?;

        Ok(())
    }

    #[tokio::test]
    async fn test_result_mapping_automatic() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: Vec<Category> = sqlx::query_as("SELECT * FROM category")
            .fetch_all(&pool)
            .await?;

        for category in result {
            println!("{:?}", category);
        }

        Ok(())
    }

    #[tokio::test]
    async fn test_result_mapping() -> Result<(), Error> {
        let pool = get_pool().await?;

        let result: Vec<Category> = sqlx::query("SELECT * FROM category")
            .map(|row: PgRow| Category {
                id: row.get("id"),
                name: row.get("name"),
                description: row.get("description"),
            })
            .fetch_all(&pool)
            .await?;

        for category in result {
            println!("{:?}", category);
        }

        Ok(())
    }

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
