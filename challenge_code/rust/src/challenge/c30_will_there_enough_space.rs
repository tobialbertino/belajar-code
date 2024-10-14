// https://www.codewars.com/kata/5875b200d520904a04000003

fn enough(cap: i32, on: i32, wait: i32) -> i32 {
    if cap >= on + wait {
        return 0;
    } else {
        return (on + wait) - cap;
    }
}

fn enough2(cap: i32, on: i32, wait: i32) -> i32 {
    match on + wait < cap {
        true =>  0,
        false => on + wait - cap,
    }
}