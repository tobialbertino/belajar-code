// https://www.codewars.com/kata/57f780909f7e8e3183000078/train/rust

pub fn grow(nums: Vec<i32>) -> i32 {
    // Code here..
    let mut res: i32 = 1;
    for i in nums.iter() {
        res *= i;
    }

    println!("{:?}", res);
    return res;
}

pub fn grow2(array: Vec<i32>) -> i32 {
    array.iter().product()
}
