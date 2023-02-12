use std::fs::File;

fn main() {
    // let v = vec![0,1,2,3];
    // println!("{}", v[6]);

    // let fruits = vec!["banana", "apple", "coconout"];

    // let first = fruits.get(0);
    // println!("{:?}", first);
    // let third = fruits.get(2);
    // println!("{:?}", third);
    // let non_existent = fruits.get(99);
    // println!("{:?}", non_existent);

    let _f = File::open("Hello.txt");
    // also can use .unwrap() or .expect(err) with err message

    // let f = match f {
    //     Ok(file) => file,
    //     Err(error) => panic!("can't open the file: {}", error),
    // };
}
