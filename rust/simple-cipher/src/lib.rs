pub fn encode(key: &str, s: &str) -> Option<String> {
    if key.is_empty() || key.chars().any(|c| !c.is_ascii_lowercase()) {
        return None;
    }

    let mut ret = String::new();
    let ks: Vec<u8> = key.bytes().collect();
    for (i, b) in s.bytes().enumerate() {
        let key_index = i % key.len();
        let diff1 = b - b'a';
        let diff2 = ks[key_index] - b'a';
        let diff = (diff1 + diff2) % 26;
        ret.push((b'a' + diff) as char);
    }

    Some(ret)
}

pub fn decode(key: &str, s: &str) -> Option<String> {
    if key.is_empty() || key.chars().any(|c| !c.is_ascii_lowercase()) {
        return None;
    }

    let mut ret = String::new();
    let ks: Vec<u8> = key.bytes().collect();
    for (i, b) in s.bytes().enumerate() {
        let key_index = i % key.len();
        let diff = if b >= ks[key_index] {
            b - ks[key_index]
        } else {
            (b + 26) - ks[key_index]
        };

        ret.push((diff + b'a') as char);
    }

    Some(ret)
}

pub fn encode_random(s: &str) -> (String, String) {
    unimplemented!(
        "Generate random key with only a-z chars and encode {}. Return tuple (key, encoded s)",
        s
    )
}
