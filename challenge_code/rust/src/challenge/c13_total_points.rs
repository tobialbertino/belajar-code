// https://www.codewars.com/kata/5bb904724c47249b10000131/train/rust

fn points(games: &[String]) -> u32 {
    games
        .iter()
        .map(|s| {
            let (l, r) = s.split_once(':').unwrap();
            match l.cmp(r) {
                std::cmp::Ordering::Less => 0,
                std::cmp::Ordering::Equal => 1,
                std::cmp::Ordering::Greater => 3,
            }
        })
        .sum()
}

fn points1(games: &[String]) -> u32 {
    games
        .iter()
        .map(|x| {
            let a = x.chars().nth(0).unwrap().to_digit(10);
            let b = x.chars().nth(2).unwrap().to_digit(10);
            if a > b {
                return 3;
            } else if a < b {
                return 0;
            }
            1
        })
        .reduce(|a, b| a + b)
        .unwrap()
}

fn points0(games: &[String]) -> u32 {
    let mut points: u32 = 0;

    for str in games {
        let str_split: Vec<&str> = str.split(":").collect();
        if str_split[0] > str_split[1] {
            points += 3
        }

        if str_split[0] == str_split[1] {
            points += 1
        }
    }

    points
}
