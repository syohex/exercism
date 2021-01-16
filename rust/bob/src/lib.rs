pub fn reply(message: &str) -> &str {
    let cs: Vec<char> = message
        .trim()
        .chars()
        .filter(|c| c.is_alphabetic())
        .collect();
    let all_upper = cs.len() >= 1 && cs.iter().all(|c| c.is_uppercase());
    if all_upper && message.trim_end().ends_with('?') {
        "Calm down, I know what I'm doing!"
    } else if message.trim().len() == 0 {
        "Fine. Be that way!"
    } else if all_upper {
        "Whoa, chill out!"
    } else if message.trim_end().ends_with('?') {
        "Sure."
    } else {
        "Whatever."
    }
}
