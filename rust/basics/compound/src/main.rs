fn main() {
    let array = [1u32, 2, 3];
    println!("access array variable: {}", array[0]);
    
    let tuple: (u32, i32, bool) = (1u32, 2, true);
    println!("access tuple variable: {}", tuple.0);
}
