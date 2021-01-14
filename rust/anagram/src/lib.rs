use std::collections::HashMap;
use std::collections::HashSet;

fn string_to_map(str: &str) -> HashMap<char, i32> {
    str.to_lowercase()
        .chars()
        .fold(HashMap::new(), |mut acc, c| {
            *acc.entry(c).or_insert(0) += 1;
            acc
        })
}

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let lower_word = word.to_lowercase();
    let word_map = string_to_map(&word);
    possible_anagrams
        .iter()
        .copied()
        .filter(|x| lower_word != x.to_lowercase())
        .filter(|s| word_map == string_to_map(&s))
        .collect()
}
