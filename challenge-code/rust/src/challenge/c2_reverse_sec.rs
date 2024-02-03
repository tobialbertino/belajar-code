// https://www.codewars.com/kata/5a00e05cc374cb34d100000d

pub fn reverse_seq(n: u32) -> Vec<u32> {
    let mut res: Vec<u32> = Vec::new();
    
    for i in (1..=n).rev() {
        res.push(i)
    }

    println!("{:?}", res);
    res
}

pub fn reverse_seq2(n: u32) -> Vec<u32> {
    (1..=n).rev().collect()
}
