fn main() {
    let output = last_char(String::from("Hello"));
    println!("last char from string is: {}", output)
}

fn last_char(string: String) -> char {
    if string.is_empty() {
        return '🚨';
    }
    string.chars().next_back().unwrap() // last code without ';' will be output, same as below
    // return string.chars().next_back().unwrap();
}