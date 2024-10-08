use axum::extract::Json;
use axum::response::Html;
use axum::response::Json as AxumJson;
use serde_json::json;

use super::model::model;

pub async fn handler() -> Html<&'static str> {
    Html("<h1>Hello, World!</h1>")
}

pub async fn test_handler() -> AxumJson<serde_json::Value> {
    AxumJson(json!({ "message": "Test" }))
}

pub async fn post_handler(Json(payload): Json<model::Input>) -> AxumJson<serde_json::Value> {
    AxumJson(json!({ "message": payload.message }))
}

pub async fn add_handler(Json(payload): Json<model::Input2Number>) -> AxumJson<serde_json::Value> {
    let total = payload.number_1 + payload.number_2;
    AxumJson(json!({ "total_number": total }))
}
