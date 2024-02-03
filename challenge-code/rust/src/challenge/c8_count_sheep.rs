// https://www.codewars.com/kata/5b077ebdaf15be5c7f000077

use std::fmt::format;

pub fn count_sheep(n: u32) -> String {
    let mut res:String = String::new();
    
    for i in 1..=n {
        res.push_str(format(format_args!("{i} sheep...")).as_str());
    }

    return res;
}

fn count_sheep2(n: u32) -> String {
    (1..=n)
        .map(|i| format!("{} sheep...", i))
        .collect::<String>()
}
