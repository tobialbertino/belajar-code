#[test]
fn test_say_hello() {
    let result = hello::say_hello("Tobi");
    assert_eq!(result, "Hello Tobi!")
}