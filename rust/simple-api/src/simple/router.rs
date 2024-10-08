use axum::{
    routing::{get, post},
    Router,
};

use super::handler;

pub fn register_routes() -> Router {
    Router::new()
        .route("/", get(handler::handler))
        .route("/test", get(handler::test_handler))
        .route("/test", post(handler::post_handler))
        .route("/add", post(handler::add_handler))
}
