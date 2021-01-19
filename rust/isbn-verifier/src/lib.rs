/// Determines whether the supplied string is a valid ISBN number
pub fn is_valid_isbn(isbn: &str) -> bool {
    let without_dash: Vec<u8> = isbn.bytes().filter(|b| *b != b'-').collect();
    if without_dash.len() != 10 {
        return false;
    }

    if let Some(pos) = without_dash.iter().position(|b| *b == b'X') {
        if pos != without_dash.len() - 1 {
            return false;
        }
    }

    if !without_dash
        .iter()
        .all(|b| (*b >= b'0' && *b <= b'9') || *b == b'X')
    {
        return false;
    }

    without_dash
        .into_iter()
        .rev()
        .filter(|b| (*b >= b'0' && *b <= b'9') || *b == b'X')
        .enumerate()
        .fold(0, |acc, (i, b)| {
            let n = if b == b'X' { 10 } else { (b - b'0') as usize };
            acc + ((i + 1) * n)
        })
        % 11
        == 0
}
