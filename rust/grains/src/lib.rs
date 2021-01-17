pub fn square(s: u32) -> u64 {
    if s == 0 || s > 64 {
        panic!("Square must be between 1 and 64")
    }
    2u64.pow(s - 1) as u64
}

pub fn total() -> u64 {
    (1u32..=64).fold(0, |acc, n| acc + square(n))
}
