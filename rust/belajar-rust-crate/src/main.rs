use say_hello_tobialbertino::{say_hello, say_goodbye};

fn main() {
    let response = say_hello("Tobi");
    println!("{}", response);

    let response = say_goodbye("Tobi");
    println!("{}", response);
}
