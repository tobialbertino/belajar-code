use axum::extract::Json as AxumJson;
use axum::response::Html;
use axum::response::Json;
use serde::Deserialize;
use serde_json::json;

pub async fn handler() -> Html<&'static str> {
    Html("<h1>Hello, World!</h1>")
}

pub async fn test_handler() -> Json<serde_json::Value> {
    Json(json!({ "message": "Test" }))
}

#[derive(Deserialize)]
pub struct Input {
    message: String,
}

pub async fn post_handler(AxumJson(payload): AxumJson<Input>) -> Json<serde_json::Value> {
    Json(json!({ "message": payload.message }))
}
