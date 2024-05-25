fn main() {
    println!("Hello, world!");
}

#[test]
fn hello_test() {
    eprintln!("Hello Test")
}

#[test]
fn test_variable() {
    let name = "M Khoiru Tobi";
    println!("Hello {}", name);
}

#[test]
fn test_mutable() {
    let mut name = "M Khoiru Tobi";
    println!("Hello {}", name);

    name = "Budi Nugraha";
    println!("Hello {}", name);
}

#[test]
fn static_typing() {
    let name = "M Khoiru Tobi";
    println!("Hello {}", name);

    // name = 10;
    println!("Hello {}", name);
}

#[test]
fn shadowing() {
    let name = "M Khoiru Tobi";
    println!("Hello {}", name);

    let name = 10;
    println!("Hello {}", name);
}

/*
This comment multi row
This comment multi row
*/
#[test]
fn comment() {
    // this is comment, only 1 row
    println!("Hello");
}

#[test]
fn explicit() {
    let age: i32 = 20;
    println!("{}", age);
}

#[test]
fn number() {
    let a: i32 = 10;
    println!("{}", a);

    let b: f64 = 10.5;
    println!("{}", b);
}

#[test]
fn number_conversion() {
    let a: i8 = 10;
    println!("{}", a);

    let b: i16 = a as i16;
    println!("{}", b);

    let c: i32 = b as i32;
    println!("{}", c);

    let d: i64 = 1_000_000_000;
    let e: i8 = d as i8;
    println!("{}", e);
}
