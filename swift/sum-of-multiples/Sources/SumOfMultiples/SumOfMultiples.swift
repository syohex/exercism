//Solution goes in Sources

public func toLimit(n: Int, inMultiples: [Int]) -> Int {
    var ret = 0
    let nums = inMultiples.filter { $0 != 0 }
    for i in 0..<n {
        for j in nums {
            if i % j == 0 {
                ret += i
                break
            }
        }
    }

    return ret
}