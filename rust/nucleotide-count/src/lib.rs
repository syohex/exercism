use std::collections::HashMap;

pub fn count(nucleotide: char, dna: &str) -> Result<usize, char> {
    let valids = vec!['A', 'C', 'G', 'T'];
    if valids.iter().find(|&c| nucleotide == *c).is_none() {
        return Err(nucleotide);
    }

    let mut count = 0_usize;
    for c in dna.chars() {
        if valids.iter().find(|&cc| c == *cc).is_none() {
            return Err(c);
        }

        if nucleotide == c {
            count += 1;
        }
    }

    Ok(count)
}

pub fn nucleotide_counts(dna: &str) -> Result<HashMap<char, usize>, char> {
    let valids = vec!['A', 'C', 'G', 'T'];
    let mut h: HashMap<char, usize> = HashMap::new();
    for &c in &valids {
        h.insert(c, 0);
    }

    for c in dna.chars() {
        if valids.iter().find(|&cc| c == *cc).is_none() {
            return Err(c);
        }

        *h.entry(c).or_insert(0) += 1;
    }

    Ok(h)
}
