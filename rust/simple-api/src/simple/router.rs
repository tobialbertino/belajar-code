use axum::{
    routing::{get, post},
    Router,
};

use super::handler;

pub fn register_routes() -> Router {
    Router::new()
        .route("/simple", get(handler::handler))
        .route("/simple/test", get(handler::test_handler))
        .route("/simple/test", post(handler::post_handler))
        .route("/simple/add", post(handler::add_handler))
}
