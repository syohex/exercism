pub fn annotate(minefield: &[&str]) -> Vec<String> {
    let mut ret: Vec<String> = vec![];
    let minefield_bs: Vec<Vec<u8>> = minefield.iter().map(|s| s.bytes().collect()).collect();

    let row_len = minefield.len() as i32;
    for (i, s) in minefield_bs.iter().enumerate() {
        let mut row_str: String = String::new();
        let col_len = s.len() as i32;
        for (j, b) in s.iter().enumerate() {
            if *b == b'*' {
                row_str.push('*');
            } else {
                let mut count = 0;
                for k in (-1..=1).into_iter() {
                    for m in (-1..=1).into_iter() {
                        let row = i as i32 + k;
                        let col = j as i32 + m;
                        if row >= 0 && row < row_len && col >= 0 && col < col_len {
                            if minefield_bs[row as usize][col as usize] == b'*' {
                                count += 1;
                            }
                        }
                    }
                }

                if count > 0 {
                    row_str.push((b'0' + count) as char);
                } else {
                    row_str.push(' ');
                }
            }
        }

        ret.push(row_str);
    }

    ret
}
