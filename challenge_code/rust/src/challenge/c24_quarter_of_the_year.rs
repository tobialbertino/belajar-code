// https://www.codewars.com/kata/56f69d9f9400f508fb000ba7/train/rust

fn quarter_of(month: u8) -> u8 {
    if month <= 3 {
        return 1;
    }
    if month <= 6 {
        return 2;
    }
    if month <= 9 {
        return 3;
    }

    return 4;
}
