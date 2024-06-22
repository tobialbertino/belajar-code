pub fn say_hello(name: &str) -> String {
    format!("Hello {}!", name)
}

mod tests {
    use super::say_hello;

    #[test]
    fn test_say_hello() {
        let hello = say_hello("Tobi");
        assert_eq!(hello, "Hello Tobi!")
    }
}