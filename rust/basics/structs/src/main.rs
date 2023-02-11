struct Person {
    name: String,
    age: u32,
    likes_oranges: bool,
}

struct Point2D(u32, u32);

fn main() {
    let person = Person {
        name: String::from("Tobi"),
        age: 23,
        likes_oranges: true,
    };

    println!("Person name is: {}", person.name);
    println!("Person age is: {}", person.age);
    println!("Person likes_oranges is: {}", person.likes_oranges);

    let origin = Point2D(100, 200);

    println!("Point contains {:?} and {:?}", origin.0, origin.1);
    
    let Point2D(x, y) = origin;
    println!("Point contains {:?} and {:?}", x, y);
}
