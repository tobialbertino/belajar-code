// https://www.codewars.com/kata/577a98a6ae28071780000989

fn minimum(arr: &[i32]) -> i32 {
    *arr.iter().min().unwrap()
}

fn maximum(arr: &[i32]) -> i32 {
    *arr.iter().max().unwrap()
}

fn minimum0(arr: &[i32]) -> i32 {
    let mut res: i32 = arr[0];

    for i in 0..arr.len() {
        if arr[i] < res {
            res = arr[i];
        }
    }

    res
}

fn maximum0(arr: &[i32]) -> i32 {
    let mut res: i32 = arr[0];

    for i in 0..arr.len() {
        if arr[i] > res {
            res = arr[i];
        }
    }

    res
}
