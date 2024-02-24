// https://www.codewars.com/kata/5772da22b89313a4d50012f7/rust

fn greet(name: &str, owner: &str) -> String {
    const BOSS: &str = "Hello boss";
    const GUEST: &str = "Hello guest";

    if name == owner {
        return BOSS.to_string();
    } else {
        return GUEST.to_string();
    }
}
