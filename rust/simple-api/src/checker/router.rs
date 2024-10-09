use axum::{
    routing::get,
    Router,
};

use super::handler;
use tower_http::trace::TraceLayer;

// TODO fix simple logging 
pub fn register_routes() -> Router {
    Router::new()
        .route("/checker/test", get(handler::test_handler))
        .layer(TraceLayer::new_for_http())

}
