// https://www.codewars.com/kata/55cbd4ba903825f7970000f5/train/rust

fn get_grade(s1: u16, s2: u16, s3: u16) -> char {
    let average = (s1 + s2 + s3) / 3;
    
    match average {
        90.. => 'A',
        80.. => 'B',
        70.. => 'C',
        60.. => 'D',
        _ => 'F'
    }
}


fn get_grade0(s1: u16, s2: u16, s3: u16) -> char {
    let score = (s1 + s2 + s3) / 3;

    if score < 60 {return 'F'}
    if score < 70 {return 'D'}
    if score < 80 {return 'C'}
    if score < 90 {return 'B'}
    'A'
}