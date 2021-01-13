pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    let fs: Vec<&u32> = factors.iter().filter(|&&x| x != 0u32).collect();
    (1..limit).filter(|n| fs.iter().any(|&&m| n % m == 0)).sum()
}
