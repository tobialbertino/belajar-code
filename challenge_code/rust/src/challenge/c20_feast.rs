// https://www.codewars.com/kata/5aa736a455f906981800360d/train/rust

fn feast2(beast: &str, dish: &str) -> bool {
    &beast[..1] == &dish[..1] && &beast[beast.len()-1..] == &dish[dish.len()-1..]
}


fn feast(beast: &str, dish: &str) -> bool {
    let l_match = beast.chars().nth(0).unwrap() == dish.chars().nth(0).unwrap();
    let r_match =
        beast.chars().nth(beast.len() - 1).unwrap() == dish.chars().nth(dish.len() - 1).unwrap();
    return l_match == r_match;
}

fn feast3(beast: &str, dish: &str) -> bool {
    beast.chars().next() == dish.chars().next() 
    && beast.chars().last() == dish.chars().last()
}
