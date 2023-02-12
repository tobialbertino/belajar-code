use std::{vec, collections::HashMap};

fn main() {
    let mut students = vec![Student {
        name: "Tobi".to_string(),
    }];
    students.push(Student {
        name: "Lisa".to_string(),
    });

    assert!(
        &students[0]
            == &Student {
                name: "Tobi".to_string()
            }
    );

    assert!(
        students.get(0)
            == Some(&Student {
                name: "Tobi".to_string()
            })
    );

    assert!(students.get(1000) == None);

    for student in students.iter() {
        println!("Student name: {}", student.name);
    }
    println!("{:?}", Some(&students));

    let mut enrollment = HashMap::new();
    enrollment.insert("biology".to_string(), students);

    let bio_students = enrollment.get("biology");
    // let students = enrollment.remove("biology");
    println!("{:?}", Some(&bio_students));
}

#[derive(PartialEq, Eq, Debug)]
struct Student {
    name: String,
}
