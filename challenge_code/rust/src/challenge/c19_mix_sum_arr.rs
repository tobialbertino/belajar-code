// https://www.codewars.com/kata/57eaeb9578748ff92a000009/go

use either::Either;

fn sum_mix(arr: &[Either<i32, String>]) -> i32 {
    let mut result = 0;
    for element in arr {
        match element {
            Either::Left(x) => result += x,
            Either::Right(x) => result += x.parse::<i32>().unwrap(),
        }
    }
    result
}

fn sum_mix2(arr: &[Either<i32, String>]) -> i32 {
    let mut sum: i32 = 0;

    for v in arr {
        if let Either::Left(num) = v {
            sum += num;
        }
        if let Either::Right(str) = v {
            let str_int = str.parse::<i32>().unwrap();
            sum += str_int;
        }
    }
    sum
}
