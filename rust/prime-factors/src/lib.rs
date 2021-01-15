pub fn factors(n: u64) -> Vec<u64> {
    let mut v: Vec<u64> = vec![];
    let mut num = n;
    let mut m = 1u64;

    while num % 2 == 0 {
        v.push(2);
        num /= 2;
        m *= 2;
    }

    let mut i = 3;
    while m != n {
        while num % i == 0 {
            v.push(i);
            num /= i;
            m *= i;
        }

        i += 2;
    }

    v
}
