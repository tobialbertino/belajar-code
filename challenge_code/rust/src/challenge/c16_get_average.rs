// https://www.codewars.com/kata/563e320cee5dddcf77000158/train/rust

fn get_average(marks: &[i32]) -> i32 {
    marks.iter().sum::<i32>() / marks.len() as i32
}

fn get_average0(marks: &[i32]) -> i32 {
    let total: i32 = marks.into_iter().sum();

    let i32_len = marks.len() as i32;

    let result = total / i32_len;
    result
}
