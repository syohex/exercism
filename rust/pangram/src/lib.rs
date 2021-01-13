use std::collections::HashSet;

pub fn is_pangram(sentence: &str) -> bool {
    let s: HashSet<u8> = sentence
        .to_lowercase()
        .bytes()
        .filter(|&c| c >= b'a' && c <= b'z')
        .collect();
    s.len() == 26
}
