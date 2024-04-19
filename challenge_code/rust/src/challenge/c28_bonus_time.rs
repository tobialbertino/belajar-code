// https://www.codewars.com/kata/56f6ad906b88de513f000d96/train/rust

fn bonus_time(mut salary: u64, bonus: bool) -> String {
    if bonus {
        salary *= 10;
    }

    let str_salary = salary.to_string();

    let mut result = ("¥").to_owned();
    result.push_str(&str_salary);
    return result;
}

fn bonus_time(salary: u64, bonus: bool) -> String {
    let mut pay = 0;
    match bonus {
        true => pay = salary * 10,
        false => pay = salary
    }
    return format!("¥{}",pay)
}

fn bonus_time(salary: u64, bonus: bool) -> String {
    format!("¥{}", salary * if bonus {10} else {1})
  }
  