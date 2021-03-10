pub fn find_saddle_points(input: &[Vec<u64>]) -> Vec<(usize, usize)> {
    let mut ret = Vec::new();
    for i in 0..input.len() {
        for j in 0..input[i].len() {
            let cur = input[i][j];
            if (0..input[i].len()).all(|n| cur >= input[i][n]) && (0..input.len()).all(|n| cur <= input[n][j]) {
                ret.push((i, j));
            }
        }
    }

    ret
}
