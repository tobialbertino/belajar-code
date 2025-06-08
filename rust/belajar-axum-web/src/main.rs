use axum::{serve, Router};
use axum::routing::{get, post};
use axum_test::TestServer;
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

#[tokio::test]
async fn test_axum() {
    let app = Router::new()
        .route("/", get(|| async { "Hello, world!" }));

    let server = TestServer::new(app).unwrap();
    let response = server.get("/").await;

    response.assert_status_ok();
    response.assert_text("Hello, world!");
}

#[tokio::test]
async fn test_method_routing() {
    async fn hello_world() -> String {
        "Hello, world!".to_string() 
    }

    let app = Router::new()
        .route("/get", get(hello_world))
        .route("/post", post(hello_world));

    let server = TestServer::new(app).unwrap();
    let response = server.get("/get").await;
    response.assert_status_ok();
    response.assert_text("Hello, world!");
    
    let response = server.post("/post").await;
    response.assert_status_ok();
    response.assert_text("Hello, world!");
}