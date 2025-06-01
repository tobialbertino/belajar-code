use axum::{serve, Router};
use axum::routing::get;
use tokio::net::TcpListener;

#[tokio::main]
async fn main() {
    let app  = Router::new()
        .route("/", get(|| async { "Hello, world!" }));

    let listener = TcpListener::bind("127.0.0.1:3000").await.unwrap();
    
    serve(listener, app)
        .await
        .unwrap();
}
