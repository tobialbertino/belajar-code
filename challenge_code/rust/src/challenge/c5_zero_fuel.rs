// https://www.codewars.com/kata/5861d28f124b35723e00005e/c 

pub fn zero_fuel(distance_to_pump: u32, mpg: u32, gallons: u32) -> bool {
    return (mpg * gallons) >= distance_to_pump;
}
