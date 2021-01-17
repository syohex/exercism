pub fn primes_up_to(upper_bound: u64) -> Vec<u64> {
    let mut v: Vec<bool> = vec![true; (upper_bound + 1) as usize];
    v[0] = false;
    v[1] = false;

    for i in (2..=upper_bound).into_iter() {
        if v[i as usize] {
            let mut j = 2;

            while i * j <= upper_bound {
                let index = (i * j) as usize;
                v[index] = false;
                j += 1;
            }
        }
    }

    let mut ret: Vec<u64> = vec![];
    for (i, ok) in v.iter().enumerate() {
        if *ok {
            ret.push(i as u64);
        }
    }

    ret
}
