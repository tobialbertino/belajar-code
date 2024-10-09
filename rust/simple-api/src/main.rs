mod constants;
mod simple;
mod checker;

use axum::Router;
use tracing_subscriber::{layer::SubscriberExt, util::SubscriberInitExt};

#[tokio::main]
async fn main() {
    tracing_subscriber::fmt()
        .with_max_level(tracing::Level::INFO)  // Set log level to INFO
        .with_target(false)  // Disable target field (optional for simplicity)
        .init();

    // build our application with a route
    let app = Router::new()
    .merge(simple::router::register_routes())
    .merge(checker::router::register_routes());

    // Bind the server to the configured port.
    let listener = match tokio::net::TcpListener::bind(format!("0.0.0.0:{}", constants::PORT)).await
    {
        Ok(listener) => {
            println!("Listening on port {}", constants::PORT);
            listener
        }
        Err(err) => {
            eprintln!("Failed to bind to port {}: {:?}", constants::PORT, err);
            return;
        }
    };

    // Start the server.
    if let Err(err) = axum::serve(listener, app).await {
        eprintln!("Failed to start server: {:?}", err);
    }
}
