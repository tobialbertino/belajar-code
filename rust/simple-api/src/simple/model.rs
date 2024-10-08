
use serde::Deserialize;

#[derive(Deserialize)]
pub struct Input {
    pub message: String,
}

#[derive(Deserialize)]
pub struct Input2Number {
    pub number_1: i64,
    pub number_2: i64,
}
