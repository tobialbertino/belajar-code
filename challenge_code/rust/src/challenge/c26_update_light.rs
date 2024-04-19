// https://www.codewars.com/kata/58649884a1659ed6cb000072/rust

use std::collections::HashMap;

fn update_light(current: &str) -> String {
    match current {
        "green" => return "yellow".to_string(),
        "yellow" => return "red".to_string(),
        "red" => return "green".to_string(),
        _ => return "wrong".to_string(),
    }
}

fn update_light2(current: &str) -> String {
    let mut rules = HashMap::new();

    rules.insert("green", "yellow");
    rules.insert("yellow", "red");
    rules.insert("red", "green");

    return rules[current].to_string();
}
