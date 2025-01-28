use config::{Case, Config, Environment, File, FileFormat};
use std::env::set_var;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
pub struct AppConfig {
    name: String,
    db: DBConfig,
}

#[derive(Debug, Deserialize)]
pub struct DBConfig {
    host: String,
    port: i32
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_config() {
    let config = Config::builder().build().unwrap();

    assert!(config.get_string("APP_NAME").is_err());
}

#[test]
fn test_config_env() {
    set_var("APP_NAME", "My App");
    set_var("APP_VERSION", "1.0.0");
    set_var("PORT", "8080");

    let config = Config::builder()
        .add_source(Environment::default().convert_case(Case::Snake))
        .build()
        .unwrap();

    assert_eq!(config.get_string("app_name").unwrap(), "My App");
    assert_eq!(config.get_string("app_version").unwrap(), "1.0.0");
    assert_eq!(config.get_int("port").unwrap(), 8080);
}

#[test]
fn test_json() {
    let config = Config::builder()
        .add_source(File::new("./application.json", FileFormat::Json))
        .build()
        .unwrap();

    assert_eq!(config.get_string("name").unwrap(), "My Application");
    assert_eq!(config.get_string("db.host").unwrap(), "localhost");
    assert_eq!(config.get_int("db.port").unwrap(), 8080);
}

#[test]
fn test_yaml() {
    let config = Config::builder()
        .add_source(File::new("./application.yaml", FileFormat::Yaml))
        .build()
        .unwrap();

    assert_eq!(config.get_string("name").unwrap(), "My Application");
    assert_eq!(config.get_string("db.host").unwrap(), "localhost");
    assert_eq!(config.get_int("db.port").unwrap(), 8080);
}

#[test]
fn test_toml() {
    let config = Config::builder()
        .add_source(File::new("./application.toml", FileFormat::Toml))
        .build()
        .unwrap();

    assert_eq!(config.get_string("name").unwrap(), "My Application");
    assert_eq!(config.get_string("db.host").unwrap(), "localhost");
    assert_eq!(config.get_int("db.port").unwrap(), 8080);
}

#[test]
fn test_deserialize() {
    let config = Config::builder()
        .add_source(File::new("./application.yaml", FileFormat::Yaml))
        .build()
        .unwrap();

    let app_config: AppConfig = config.try_deserialize().unwrap();

    assert_eq!(app_config.name, "My Application");
    assert_eq!(app_config.db.host, "localhost");
    assert_eq!(app_config.db.port, 8080);
}


