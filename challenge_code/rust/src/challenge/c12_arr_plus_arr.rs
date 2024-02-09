// https://www.codewars.com/kata/5a2be17aee1aaefe2a000151

fn slice_plus_slice(xs: &[i32], ys: &[i32]) -> i32 {

    let res1: i32 = xs.iter().sum();
    let res2: i32 = ys.iter().sum();
    
    return res1 + res2;
}

fn slice_plus_slice2(xs: &[i32], ys: &[i32]) -> i32 {
    let sum = [xs, ys].concat().into_iter().reduce(|a, b| a + b);
    match sum {
        Some(x) => x,
        None => 0,
    }
}

fn slice_plus_slice3(xs: &[i32], ys: &[i32]) -> i32 {
    xs.iter().chain(ys).sum()
}
