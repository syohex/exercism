pub struct PascalsTriangle {
    row_count: u32,
}

impl PascalsTriangle {
    pub fn new(row_count: u32) -> Self {
        Self { row_count }
    }

    pub fn rows(&self) -> Vec<Vec<u32>> {
        let mut ret: Vec<Vec<u32>> = vec![];
        if self.row_count == 0 {
            return ret;
        }

        let len = self.row_count as usize;
        for i in 1..=len {
            let mut v: Vec<u32> = vec![];
            for j in 0..i {
                if j == 0 || j == i - 1 {
                    v.push(1);
                } else {
                    v.push(ret[i - 2][j - 1] + ret[i - 2][j]);
                }
            }

            ret.push(v)
        }

        ret
    }
}
