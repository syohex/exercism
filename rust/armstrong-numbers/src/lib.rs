pub fn is_armstrong_number(num: u32) -> bool {
    let str = num.to_string();
    str.bytes().fold(0u32, |sum, b| {
        let n = (b - b'0') as u32;
        sum + n.pow(str.len() as u32)
    }) == num
}
