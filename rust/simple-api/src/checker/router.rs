use axum::{
    routing::get,
    Router,
};

use super::handler;

pub fn register_routes() -> Router {
    Router::new()
        .route("/checker/test", get(handler::test_handler))
    
}
