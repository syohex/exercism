#[derive(Debug, PartialEq, Eq)]
pub struct Palindrome {
    a: u64,
    b: u64,
}

impl Palindrome {
    pub fn new(a: u64, b: u64) -> Palindrome {
        Self { a, b }
    }

    pub fn value(&self) -> u64 {
        self.a * self.b
    }

    pub fn insert(&mut self, a: u64, b: u64) {
        self.a = a;
        self.b = b;
    }
}

pub fn palindrome_products(min: u64, max: u64) -> Option<(Palindrome, Palindrome)> {
    let mut min_val = std::u64::MAX;
    let mut min_p = Palindrome::new(0, 0);
    let mut ok = false;

    let mut max_val = 0u64;
    let mut max_p = Palindrome::new(0, 0);

    for i in (min..=max).into_iter() {
        if i % 10 == 0 {
            continue;
        }

        for j in (i..=max).into_iter() {
            let mul = i * j;
            if mul % 10 == 0 {
                continue;
            }

            let str = mul.to_string();
            let rev: String = mul.to_string().chars().rev().collect();
            if str != rev {
                continue;
            }

            ok = true;

            if mul < min_val {
                min_val = mul;
                min_p.insert(i, j);
            }

            if mul >= max_val {
                max_val = mul;
                max_p.insert(i, j);
            }
        }
    }

    if ok {
        Some((min_p, max_p))
    } else {
        None
    }
}
