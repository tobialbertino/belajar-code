// https://www.codewars.com/kata/5513795bd3fafb56c200049e

fn count_by(x: u32, n: u32) -> Vec<u32> {
    let mut res: Vec<u32> = Vec::new();

    for i in 1..=n {
        res.push(i * x);
    }

    res
}
