use axum::response::Json as AxumJson;
use serde_json::json;

use axum::http::StatusCode;
use axum::response::IntoResponse;

pub async fn test_handler() -> impl IntoResponse {
    let body = AxumJson(json!({ "message": "Test", "status": "OK" }));
    (StatusCode::NOT_FOUND, body)
}