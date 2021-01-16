pub fn brackets_are_balanced(string: &str) -> bool {
    let mut v: Vec<char> = vec![];
    for c in string.chars() {
        match c {
            '[' | '(' | '{' => v.push(c),
            ']' => {
                if let Some(d) = v.pop() {
                    if d != '[' {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            ')' => {
                if let Some(d) = v.pop() {
                    if d != '(' {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            '}' => {
                if let Some(d) = v.pop() {
                    if d != '{' {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            _ => {}
        }
    }

    v.is_empty()
}
