use handlebars::{
    Context, Handlebars, Helper, HelperDef, HelperResult, Output, RenderContext, handlebars_helper,
};
use serde::Serialize;
use serde_json::json;
use std::collections::HashMap;

struct DoubleNumber;

impl HelperDef for DoubleNumber {
    fn call<'reg: 'rc, 'rc>(
        &self,
        h: &Helper<'rc>,
        r: &'reg Handlebars<'reg>,
        ctx: &'rc Context,
        rc: &mut RenderContext<'reg, 'rc>,
        out: &mut dyn Output,
    ) -> HelperResult {
        let param = h.param(0).unwrap();
        let number = param.value().as_i64().unwrap();
        let doubled = number * 2;
        out.write(&doubled.to_string())?;
        Ok(())
    }
}

#[derive(Serialize)]
struct Address {
    street: String,
    city: String,
}

#[derive(Serialize)]
struct Person {
    first_name: String,
    last_name: String,
    hobbies: Vec<String>,
    addresses: Vec<Address>,
}

#[derive(Serialize)]
struct Data {
    person: Person,
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn test_handlebars() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_string("hello", "Hello, {{name}}!")
        .unwrap();
    handlebars
        .register_template_string("bye", "Bye, {{name}}")
        .unwrap();

    let mut data = HashMap::new();
    data.insert("name", "Tobi");

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered, "Hello, Tobi!");

    let rendered = handlebars.render("bye", &data).unwrap();
    assert_eq!(rendered, "Bye, Tobi");
}

#[test]
fn test_nested_variables() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_string("hello", "Hello {{person.first_name}} {{person.last_name}}")
        .unwrap();

    let mut data = HashMap::new();
    let mut person = HashMap::new();
    person.insert("first_name", "Tobi");
    person.insert("last_name", "Albertino");

    data.insert("person", person);

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered, "Hello Tobi Albertino");
}

#[test]
fn test_html_escape() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_string("hello", "Hello, {{{name}}}!")
        .unwrap();

    let mut data = HashMap::new();
    data.insert("name", "<p>Tobi</p>");

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered, "Hello, <p>Tobi</p>!");
}

#[test]
fn test_template_file() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("hello", "templates/hello.mustache")
        .unwrap();

    let mut data = HashMap::new();
    data.insert("name", "Tobi");

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered, "Hello, Tobi!");
}

#[test]
fn test_with() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("hello", "templates/with-hello.mustache")
        .unwrap();

    let mut data = HashMap::new();
    let mut person = HashMap::new();
    person.insert("first_name", "Tobi");
    person.insert("last_name", "Albertino");

    data.insert("person", person);

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered.contains("Hello Tobi Albertino"), true);
}

#[test]
fn test_serde() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("hello", "templates/with-hello.mustache")
        .unwrap();

    let data = Data {
        person: Person {
            first_name: "Tobi".to_string(),
            last_name: "Albertino".to_string(),
            hobbies: vec![],
            addresses: vec![],
        },
    };

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered.contains("Hello Tobi Albertino"), true);
}

#[test]
fn test_serde_json() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("hello", "templates/with-hello.mustache")
        .unwrap();

    let data = json!({
        "person": {
            "first_name": "Tobi",
            "last_name": "Albertino"
        }
    });

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered.contains("Hello Tobi Albertino"), true);
}

#[test]
fn test_if() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("layout/header", "templates/layout/header.mustache")
        .unwrap();
    handlebars
        .register_template_file("layout/footer", "templates/layout/footer.mustache")
        .unwrap();
    handlebars
        .register_template_file("hello", "templates/blog.mustache")
        .unwrap();

    let data = json!({
        "title" : "Belajar Rust",
        "content" : "Belajar Rust dengan baik",
        "footer" : "Programmer Zaman Now"
    });

    let rendered = handlebars.render("hello", &data).unwrap();
    println!("{}", rendered);

    assert_eq!(rendered.contains("Belajar Rust"), true);
    assert_eq!(rendered.contains("Belajar Rust dengan baik"), true);
    assert_eq!(rendered.contains("Anonymous"), true);
    assert_eq!(rendered.contains("Programmer Zaman Now"), true);
}

#[test]
fn test_if2() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("hello", "templates/blog.mustache")
        .unwrap();

    let data = json!({
        "title": "Belajar Rust",
        "content": "Belajar Rust",
        "author": "Tobi"
    });

    let rendered = handlebars.render("hello", &data).unwrap();
    assert_eq!(rendered.contains("Belajar Rust"), true);
    assert_eq!(rendered.contains("Tobi"), true);
}

#[test]
fn test_unless() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("footer", "templates/footer.mustache")
        .unwrap();

    let data = json!({});

    let rendered = handlebars.render("footer", &data).unwrap();
    assert_eq!(
        rendered.contains("this content does not contain a footer"),
        true
    );
}

#[test]
fn test_unless2() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("footer", "templates/footer.mustache")
        .unwrap();

    let data = json!({
        "footer": "footer"
    });

    let rendered = handlebars.render("footer", &data).unwrap();
    assert_eq!(
        rendered.contains("this content does not contain a footer"),
        false
    );
}

#[test]
fn test_each() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("person", "templates/person.mustache")
        .unwrap();

    let data = Person {
        first_name: "Tobi".to_string(),
        last_name: "Albertino".to_string(),
        hobbies: vec!["Coding".to_string(), "Reading".to_string()],
        addresses: vec![],
    };

    let rendered = handlebars.render("person", &data).unwrap();
    assert_eq!(rendered.contains("Tobi"), true);
    assert_eq!(rendered.contains("Albertino"), true);
    assert_eq!(rendered.contains("0 - Coding"), true);
    assert_eq!(rendered.contains("1 - Reading"), true);
}

#[test]
fn test_each_object() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_file("person", "templates/person.mustache")
        .unwrap();

    let data = Person {
        first_name: "Tobi".to_string(),
        last_name: "Albertino".to_string(),
        hobbies: vec!["Coding".to_string(), "Reading".to_string()],
        addresses: vec![
            Address {
                street: "Jalan Raya 1".to_string(),
                city: "Jakarta".to_string(),
            },
            Address {
                street: "Jalan Raya 2".to_string(),
                city: "Bandung".to_string(),
            },
        ],
    };

    let rendered = handlebars.render("person", &data).unwrap();
    assert_eq!(rendered.contains("Tobi"), true);
    assert_eq!(rendered.contains("Albertino"), true);
    assert_eq!(rendered.contains("0 - Coding"), true);
    assert_eq!(rendered.contains("1 - Reading"), true);
    assert_eq!(rendered.contains("street - Jalan Raya 1"), true);
    assert_eq!(rendered.contains("street - Jalan Raya 2"), true);
    assert_eq!(rendered.contains("city - Jakarta"), true);
    assert_eq!(rendered.contains("city - Bandung"), true);
}

#[test]
fn test_helper() {
    let mut handlebars = Handlebars::new();

    handlebars
        .register_template_string("helper", "result : {{double value}}")
        .unwrap();

    handlebars.register_helper("double", Box::new(DoubleNumber));

    let data = json!({
        "value": 10
    });

    let rendered = handlebars.render("helper", &data).unwrap();
    assert_eq!(rendered.contains("20"), true);
}

handlebars_helper!(uppercase: | value: String | {
    value.to_uppercase()
});

#[test]
fn test_helper_macro() {
    let mut handlebars = Handlebars::new();

    handlebars.register_helper("uppercase", Box::new(uppercase));   
    handlebars
        .register_template_string("helper", "result : {{uppercase value}}")
        .unwrap();

    let data = json!({
        "value": "tobi"
    });

    let rendered = handlebars.render("helper", &data).unwrap();
    println!("{}", rendered);
    assert_eq!(rendered.contains("TOBI"), true);
}
