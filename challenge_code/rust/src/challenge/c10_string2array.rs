// https://www.codewars.com/kata/57e76bc428d6fbc2d500036d/train/rust

fn string_to_array(s: &str) -> Vec<String> {
    let array: Vec<&str> = s.split(' ').collect();
    let res: Vec<String> = array.iter().map(|&s| s.to_string()).collect();
    res
}

fn string_to_array2(s: &str) -> Vec<String> {
    s.split_whitespace().map(str::to_string).collect()
}
