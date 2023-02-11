fn main() {
    if 1 == 2 {
        println!("math is broken");
    } else {
        println!("everything is fine");
    }

    let formal = true;
    let _greeting = if formal {
        println!("Good evening");
    } else {
        println!("Hey Friend");
    };

    let number = 6;

    if number % 4 == 0 {
        println!("number is divisible by 4")
    } else if number % 3 == 0 {
        println!("number is divisible by 3")
    } else {
        println!("number is not divisible by 3 & 4")
    }

    let boolean = true;
    let _binary = match boolean {
        true => 1,
        false => 0,
    };
}
