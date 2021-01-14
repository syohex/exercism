pub fn abbreviate(phrase: &str) -> String {
    let mut v: Vec<char> = vec![];
    let cs: Vec<char> = phrase.chars().collect();
    for i in 0..phrase.len() {
        if !cs[i].is_alphabetic() {
            continue;
        }

        if i == 0 {
            v.push(cs[i].to_ascii_uppercase());
            continue;
        }

        let prev = cs[i - 1];
        if (!prev.is_alphabetic() && prev != '\'')
            || (cs[i].is_ascii_uppercase() && !prev.is_ascii_uppercase())
        {
            v.push(cs[i].to_ascii_uppercase())
        }
    }

    v.iter().collect()
}
