mod checker;
mod constants;
mod simple;

use axum::Router;
use tracing_subscriber::{layer::SubscriberExt, util::SubscriberInitExt};

#[tokio::main]
async fn main() {
    // Initialize the logger with log level control, which prints logs to the terminal
    tracing_subscriber::registry()
        .with(
            tracing_subscriber::fmt::layer()
                .with_target(false) // Optionally disable target field in logs
                .with_level(true), // Include log levels in output
        )
        .with(
            tracing_subscriber::EnvFilter::from_default_env(), // Use `RUST_LOG` to set log level
        )
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
