use serde::Serialize;
use validator::{Validate, ValidateArgs, ValidationErrors};

pub mod pzn {
    pub mod validator {
        use crate::{DatabaseContext, RegisterUserRequest};
        use std::borrow::Cow;
        use validator::ValidationError;

        pub fn not_blank(value: &str) -> Result<(), ValidationError> {
            if value.trim().is_empty() {
                return Err(ValidationError::new("value cannot be blank")
                    .with_message(Cow::from("value cannot be blank")));
            }
            Ok(())
        }

        pub fn password_equals_ocnfirm_password(
            request: &RegisterUserRequest,
        ) -> Result<(), ValidationError> {
            if request.password != request.confirm_password {
                return Err(ValidationError::new("password not equals confirm password")
                    .with_message(Cow::from("password not equals confirm password")));
            }
            Ok(())
        }

        pub fn can_register(
            request: &RegisterUserRequest,
            context: &DatabaseContext,
        ) -> Result<(), ValidationError> {
            if context.total >= context.max_data {
                return Err(
                    ValidationError::new("max data reached").with_message(Cow::from(format!(
                        "cannot register user {}, database is full",
                        request.username
                    ))),
                );
            }
            Ok(())
        }
    }
}

pub struct DatabaseContext {
    total: i32,
    max_data: i32,
}

fn main() {
    println!("Hello, world!");
}

#[derive(Debug, Validate)]
struct LoginRequest {
    #[validate(length(
        min = 3,
        max = 20,
        message = "Username must be between 3 and 20 characters"
    ))]
    username: String,

    #[validate(length(
        min = 3,
        max = 20,
        message = "Password must be between 3 and 20 characters"
    ))]
    password: String,
}

#[derive(Debug, Validate)]
struct AddressRequest {
    #[validate(length(min = 1, max = 100))]
    street: String,
    #[validate(length(min = 1, max = 100))]
    city: String,
    #[validate(length(min = 1, max = 100))]
    country: String,
}

#[derive(Debug, Validate)]
#[validate(context = DatabaseContext,
    schema(
        function = "crate::pzn::validator::password_equals_ocnfirm_password",
        skip_on_field_errors = false,
        code = "password",
        message = "password not equals confirm password",
    ),
    schema(
        function = "crate::pzn::validator::can_register",
        skip_on_field_errors = false,
        code = "username",
        message = "username is exists in DB",
        use_context,
    ),
)]
pub struct RegisterUserRequest {
    #[validate(length(min = 3, max = 20, code = "username"))]
    username: String,
    #[validate(length(min = 3, max = 20, code = "password"))]
    password: String,
    #[validate(length(min = 3, max = 20, code = "confirm_password"))]
    confirm_password: String,
    #[validate(length(min = 3, max = 100, code = "name"))]
    name: String,
    #[validate(nested)]
    address: AddressRequest,
}

#[derive(Debug, Validate)]
struct Product {
    #[validate(length(min = 1, max = 100))]
    id: String,
    #[validate(length(min = 1, max = 100))]
    name: String,
    #[validate(nested, length(min = 1))]
    varian: Vec<ProductVarian>,
}

#[derive(Debug, Validate, Serialize)]
struct ProductVarian {
    #[validate(length(min = 1, max = 100))]
    name: String,
    #[validate(range(min = 1, max = 1_000_000_000))]
    price: i32,
}

#[derive(Debug, Validate)]
struct CreateCatrgoryRequest {
    #[validate(custom(function = "crate::pzn::validator::not_blank"))]
    id: String,
    #[validate(custom(function = "crate::pzn::validator::not_blank"))]
    name: String,
}

#[test]
fn test_custom_validation() {
    let request = CreateCatrgoryRequest {
        id: "    ".to_string(),
        name: "    ".to_string(),
    };

    assert!(request.validate().is_err());

    let error: ValidationErrors = request.validate().err().unwrap();
    println!("{:?}", error.errors());
}

#[test]
fn test_valida_vector_success() {
    let product = Product {
        id: "1".to_string(),
        name: "product".to_string(),
        varian: vec![
            ProductVarian {
                name: "varian 1".to_string(),
                price: 100,
            },
            ProductVarian {
                name: "varian 2".to_string(),
                price: 200,
            },
        ],
    };

    assert!(product.validate().is_ok());
}

#[test]
fn test_valida_vector_failed() {
    let product = Product {
        id: "1".to_string(),
        name: "product".to_string(),
        varian: vec![
            ProductVarian {
                name: "".to_string(),
                price: -100,
            },
            ProductVarian {
                name: "varian 2".to_string(),
                price: -200,
            },
        ],
    };

    assert!(product.validate().is_err());

    let error: ValidationErrors = product.validate().err().unwrap();
    println!("{:?}", error.errors());
}

#[test]
fn test_nested_struct_success() {
    let request = RegisterUserRequest {
        username: "user".to_string(),
        password: "password".to_string(),
        confirm_password: "password".to_string(),
        name: "name".to_string(),
        address: AddressRequest {
            street: "street".to_string(),
            city: "city".to_string(),
            country: "country".to_string(),
        },
    };

    let context = DatabaseContext {
        total: 0,
        max_data: 10,
    };

    assert!(request.validate_with_args(&context).is_ok());
}

#[test]
fn test_nested_struct_failed() {
    let request = RegisterUserRequest {
        username: "user".to_string(),
        password: "password".to_string(),
        confirm_password: "password_not_same".to_string(),
        name: "name".to_string(),
        address: AddressRequest {
            street: "".to_string(),
            city: "".to_string(),
            country: "".to_string(),
        },
    };

    let context = DatabaseContext {
        total: 10,
        max_data: 10,
    };

    assert!(request.validate_with_args(&context).is_err());

    let error: ValidationErrors = request.validate_with_args(&context).err().unwrap();
    println!("{:?}", error.errors());
}

#[test]
fn test_validate_success() {
    let login = LoginRequest {
        username: "user".to_string(),
        password: "password".to_string(),
    };

    assert!(login.validate().is_ok());
}

#[test]
fn test_validate_failed() {
    let login = LoginRequest {
        username: "us".to_string(),
        password: "p".to_string(),
    };

    assert!(login.validate().is_err());

    let error = login.validate().err().unwrap();
    println!("{:?}", error.errors());
}
