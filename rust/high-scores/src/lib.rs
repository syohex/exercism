use std::cmp::min;

#[derive(Debug)]
pub struct HighScores {
    scores: Vec<u32>,
    sorted: Vec<u32>,
}

impl HighScores {
    pub fn new(scores: &[u32]) -> Self {
        let mut v = scores.to_vec();
        v.sort_by(|a, b| b.cmp(a));

        Self {
            scores: scores.to_vec(),
            sorted: v,
        }
    }

    pub fn scores(&self) -> &[u32] {
        &self.scores[..]
    }

    pub fn latest(&self) -> Option<u32> {
        if self.scores.is_empty() {
            None
        } else {
            let last_index = self.scores.len() - 1;
            Some(self.scores[last_index])
        }
    }

    pub fn personal_best(&self) -> Option<u32> {
        if self.sorted.is_empty() {
            None
        } else {
            Some(self.sorted[0])
        }
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        let num = min(self.sorted.len(), 3);
        self.sorted.iter().take(num).map(|n| *n).collect()
    }
}
