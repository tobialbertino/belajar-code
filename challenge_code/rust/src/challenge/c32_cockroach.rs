// https://www.codewars.com/kata/55fab1ffda3e2e44f00000c6/train/rust

fn cockroach_speed(s: f64) -> i64 {
    let cm_per_second = s * 100_000.0 / 3600.0;
    cm_per_second as i64
}