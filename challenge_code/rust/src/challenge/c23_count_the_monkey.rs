// https://www.codewars.com/kata/56f69d9f9400f508fb000ba7/train/rust

fn monkey_count(n: i32) -> Vec<i32> {
    let mut res: Vec<i32> = vec![];
    for i in 1..n + 1 {
        res.push(i);
    }

    res
}

fn monkey_count2(n: i32) -> Vec<i32> {
    (1..=n).collect()
}
