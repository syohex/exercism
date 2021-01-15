use regex::Regex;
use std::collections::HashMap;

/// Count occurrences of words.
pub fn word_count(words: &str) -> HashMap<String, u32> {
    let re = Regex::new(r"[\w']+").unwrap();
    let ws: Vec<String> = re
        .find_iter(words)
        .map(|word| word.as_str().to_lowercase())
        .map(|word| {
            let mut w = &word[..];
            if word.starts_with("'") {
                w = &w[1..];
            }
            if word.ends_with("'") {
                w = &w[..w.len() - 1];
            }
            w.to_string()
        })
        .collect();

    let mut h: HashMap<String, u32> = HashMap::new();
    for w in ws.into_iter() {
        *h.entry(w).or_insert(0) += 1;
    }

    h
}
