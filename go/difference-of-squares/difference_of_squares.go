package diffsquares

func SquareOfSum(n int) int {
	ret := 0

	for i := 1; i <= n; i++ {
		ret += i
	}

	return ret * ret
}

func SumOfSquares(n int) int {
	ret := 0

	for i := 1; i <= n; i++ {
		ret += i * i
	}

	return ret
}

func Difference(n int) int {
	return SquareOfSum(n) - SumOfSquares(n)
}
