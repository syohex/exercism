use std::collections::HashMap;

pub fn check(candidate: &str) -> bool {
    if candidate.is_empty() {
        return true;
    }

    let mut h: HashMap<char, i32> = HashMap::new();
    let cs: String = candidate
        .chars()
        .filter(|c| c.is_alphabetic())
        .flat_map(|c| c.to_lowercase())
        .collect();
    for c in cs.chars() {
        *h.entry(c).or_insert(0) += 1;
    }

    h.iter().all(|(_, count)| *count == 1)
}
