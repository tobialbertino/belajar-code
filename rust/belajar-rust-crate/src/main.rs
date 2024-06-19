use say_hello_tobialbertino::{say_hello, say_goodbye, say_hello_to_everyone, say_goodbye_to_everyone};

fn main() {
    let response = say_hello("Tobi");
    println!("{}", response);

    let response = say_goodbye("Tobi");
    println!("{}", response);

    let response = say_hello_to_everyone();
    println!("{}", response);

    let response = say_goodbye_to_everyone();
    println!("{}", response);

    // error, only dev dep or unit test
    // let id = uuid::Uuid::new_v4().to_string();
    // println!("{}", id);

    hello::say_hello();
    bye::say_bye();
}

#[test]
fn test_uuid() {
    let id = uuid::Uuid::new_v4().to_string();
    println!("{}", id);
}
