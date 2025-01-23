use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
struct UserLoginRequest {
    username: String,
    password: String,
}

#[derive(Debug, Serialize, Deserialize)]
struct AddressRequest {
    street: String,
    city: String,
    states: String,
    zip: String,
}

#[derive(Debug, Serialize, Deserialize)]
struct CreateUserRequest {
    username: String,
    password: String,
    email: String,
    address: AddressRequest,
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_create_json_for_user_login() {
    let user_login = UserLoginRequest {
        username: "admin".to_string(),
        password: "admin".to_string(),
    };

    let json = serde_json::to_string(&user_login).unwrap();
    println!("{}", json);

    let login_result: UserLoginRequest = serde_json::from_str(&json).unwrap();
    println!("{:?}", login_result);
}

#[test]
fn test_create_json_for_user_create_request() {
    let request = CreateUserRequest {
        username: "admin".to_string(),
        password: "admin".to_string(),
        email: "test@mail.com".to_string(),
        address: AddressRequest {
            street: "Jl. Jendral".to_string(),
            city: "Wakanda".to_string(),
            states: "Konoha".to_string(),
            zip: "123".to_string(),
        },
    };

    let json = serde_json::to_string(&request).unwrap();
    println!("{}", json);

    let result: CreateUserRequest = serde_json::from_str(&json).unwrap();
    println!("{:?}", result);
}

