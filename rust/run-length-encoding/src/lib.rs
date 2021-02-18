pub fn encode(source: &str) -> String {
    if source.is_empty() {
        return "".to_string();
    }

    let mut ret = String::new();
    let cs: Vec<char> = source.chars().collect();
    let mut prev = cs[0];
    let mut count = 1;

    for &c in cs.iter().skip(1) {
        if c == prev {
            count += 1;
        } else {
            if count > 1 {
                ret.push_str(&count.to_string());
            }
            ret.push(prev);

            prev = c;
            count = 1;
        }
    }

    if count > 1 {
        ret.push_str(&count.to_string());
    }
    ret.push(prev);

    ret
}

pub fn decode(source: &str) -> String {
    if source.is_empty() {
        return "".to_string();
    }

    let mut ret = String::new();
    let cs: Vec<char> = source.chars().collect();
    let mut count = 0_u32;
    let mut pos = 0_usize;
    while pos < source.len() {
        if cs[pos].is_numeric() {
            count = 10 * count + cs[pos].to_digit(10).unwrap();
        } else {
            if count > 0 {
                for _ in 0..count {
                    ret.push(cs[pos]);
                }
            } else {
                ret.push(cs[pos]);
            }

            count = 0;
        }

        pos += 1;
    }

    ret
}
