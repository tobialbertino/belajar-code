// https://www.codewars.com/kata/56b1f01c247c01db92000076

fn double_char(s: &str) -> String {
    let mut result: String = String::from("");

    // iterate string
    for ch in s.chars() {
        for _ in 0..2 {
            result.push(ch)
        }
    }

    result
}

fn double_char2(s: &str) -> String {
    s.chars().map(|f| f.to_string().repeat(2)).collect()
}

fn double_char3(s: &str) -> String {
    s.chars().flat_map(|c| [c, c]).collect()
}

fn double_char4(s: &str) -> String {
    s.chars().map(|x| format!("{}{}", x, x)).collect()
}
