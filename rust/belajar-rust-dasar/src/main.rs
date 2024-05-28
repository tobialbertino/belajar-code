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

#[test]
fn numeric_operator() {
    let a = 10;
    let b = 10;
    let c = a * b;
    println!("{}", c);
    let d = a / b;
    println!("{}", d);
    let e = a + b;
    println!("{}", e);
}

#[test]
fn augmented_assigment() {
    let mut a = 10;
    println!("{}", a);

    a += 10;
    println!("{}", a);

    a -= 10;
    println!("{}", a);
}

#[test]
fn boolean() {
    let a = true;
    let b: bool = false;
    println!("{} {}", a, b);
}

#[test]
fn comparison() {
    let a = 10;
    let b = 20;

    let result = a > b;
    println!("{}", result);
}

#[test]
fn boolean_operator() {
    let absen = 75;
    let nilai_akhir = 80;

    let lulus_absen = absen >= 75;
    let lulus_nilai_akhir = nilai_akhir >= 75;

    let lulus = lulus_absen && lulus_nilai_akhir;
    println!("{}", lulus);
}


#[test]
fn char_type() {
    let char1: char = 'a';
    let char2: char = 'b';

    println!("{} {}", char1, char2);
}

#[test]
fn tuple() {
    let mut data: (i32, f64, bool) = (10, 10.5, true);
    println!("{:?}", data);

    // let a = data.0;
    // let b = data.1;
    // let c = data.2;

    // destructor
    let (a, b, c) = data;
    println!("{} {} {}", a, b, c);

    data.0 = 20;
    data.1 = 20.5;
    data.2 = false;
    println!("{:?}", data);
}

fn unit() {
    println!("Hello");
}

#[test]
fn test_unit() {
    let result: () = unit();
    println!("{:?}", result);

    let test: () = ();
    println!("{:?}", test)
}

#[test]
fn array() {
    let mut array: [i32; 5] = [1, 2, 3, 4, 5];
    println!("{:?}", array);

    let a = array[0];
    let b = array[1];
    println!("{} {}", a, b);

    array[0] = 10;
    array[1] = 20;
    println!("{:?}", array);

    let length = array.len();
    println!("{}", length);
}

#[test]
fn two_dimensional_array() {
    let matrix: [[i32; 2]; 2] = [
        [1, 2],
        [3, 4]
    ];

    println!("{:?}", matrix);
    println!("{:?}", matrix[0]);
    println!("{}", matrix[0][0]);
}

const MAXIMUM: i32 = 100;

#[test]
fn constant() {
    const MINIMUM: i32 = 0;
    println!("{} {}", MINIMUM, MAXIMUM)
}

#[test]
fn variable_scope() {
    println!("{}", MAXIMUM);

    let eko = 1;

    { // inner scope
        println!("{}", eko);
        let kurniawan = 2;
        println!("{}", kurniawan);
    }

    // println!("{}", kurniawan); //error
}

#[test]
fn stack_heap() {
    function_a();
    function_b();
}

fn function_a() {
    let a = 10;
    let b = String::from("Tobi");
    println!("{} {}", a, b);
}

fn function_b() {
    let a = 10;
    let b = String::from("Albertino");
    println!("{} {}", a, b);
}

#[test]
fn string() {
    let name: &str = " Tobi Albertino ";
    let trim = name.trim();

    println!("{}", name);
    println!("{}", trim);
}

#[test]
fn string_type() {
    let mut name: String = String::from("Tobi");
    println!("{}", name);

    name.push_str(" Albertino");
    println!("{}", name);

    let budi = name.replace("Tobi", "Budi");
    println!("{}", name);
    println!("{}", budi);
}

#[test]
fn ownership_rules() {
    let a = 10;

    {
        let b = 10;
        println!("{}", b);
    }

    println!("{}", a);
}

#[test]
fn data_copy() {
    let a = 10;
    // for data (fixed size) store on stack memory, data will copy
    let b = a;

    println!("{} {}", a, b);
}

#[test]
fn ownership_movement() {
    let name: String = String::from("Tobi");
    println!("{}", name);

    // ownership moved, for data store on heap memory
    let name2: String = name;
    println!("{}", name2);
    // println!("{}", name1); error
}

#[test]
fn clone() {
    let name1 = String::from("Tobi");
    let name2 = name1.clone();

    println!("{} {}", name1, name2);
}

#[test]
fn if_expression() {
    let value = 6;
    let result: &str = if value >= 8 {
        "Good"
    } else if value >= 6 {
        "Not Bad"
    } else {
        "Very Bad"
    };

    println!("{}", result);
}