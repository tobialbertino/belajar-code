use std::collections::HashMap;
use handlebars::Handlebars;

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_handlebars() {
    let mut handlebars = Handlebars::new();

    handlebars.register_template_string("hello", "Hello, {{name}}!").unwrap();
    handlebars.register_template_string("bye", "Bye, {{name}}").unwrap();

    let mut data = HashMap::new();
    data.insert("name", "Tobi");

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered, "Hello, Tobi!");
    
    let rendered = handlebars.render("bye", &data).unwrap();
    assert_eq!(rendered, "Bye, Tobi");
}