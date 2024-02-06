// https://www.codewars.com/kata/5672a98bdbdd995fad00000f

use std::collections::{hash_map, HashMap};

fn rps(p1: &str, p2: &str) -> &'static str {
    let player_1: &'static str = "Player 1 won!";
    let player_2: &'static str = "Player 2 won!";
    let draw: &'static str = "Draw!";

    if p1 == p2 {
        return draw;
    }

    let mut map: HashMap<&str, &str> = HashMap::from([
        ("rock", "scissors"),
        ("paper", "rock"),
        ("scissors", "paper"),
    ]);

    if map[p1] == p2 {
        return player_1;
    } else {
        return player_2;
    }
    return draw;
}
