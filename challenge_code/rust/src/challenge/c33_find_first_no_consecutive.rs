// https://www.codewars.com/kata/58f8a3a27a5c28d92e000144/train/rust


fn first_non_consecutive(arr: &Vec<i32>) -> Option<i32> {
    for window in arr.windows(2) {
        if let [a, b] = window {
            if *b != a + 1 {
                return Some(*b);
            }
        }
    }
    None
  }