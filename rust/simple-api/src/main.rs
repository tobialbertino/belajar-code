mod constants;
mod simple;
mod checker;

use axum::Router;

#[tokio::main]
async fn main() {
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
