#[derive(Debug, PartialEq, Eq)]
pub enum Classification {
    Abundant,
    Perfect,
    Deficient,
}

pub fn classify(num: u64) -> Option<Classification> {
    if num == 0 {
        return None;
    }

    let n = if num == 1 {
        0
    } else {
        (1..=(num / 2)).filter(|&n| num % n == 0).sum::<u64>()
    };

    if n == num {
        Some(Classification::Perfect)
    } else if n > num {
        Some(Classification::Abundant)
    } else {
        Some(Classification::Deficient)
    }
}
