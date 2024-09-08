// https://codewars.com/kata/5769b3802ae6f8e4890009d2/train/rust

fn remove_every_other(arr: &[u8]) -> Vec<u8> {
    arr.iter()
        .enumerate()
        .filter_map(|(index, &value)| {
            if index % 2 == 0 {
                Some(value)
            } else {
                None
            }
        })
        .collect()
}