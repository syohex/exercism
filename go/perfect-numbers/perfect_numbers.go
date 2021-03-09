package perfect

import "errors"

type Classification int

const (
	ClassificationAbundant Classification = iota
	ClassificationDeficient
	ClassificationPerfect
)

var ErrOnlyPositive = errors.New("hoge")

func sumOfDivisors(n int64) int64 {
	var ret int64 = 0
	var i int64
	for i = 1; i < n; i++ {
		if n%i == 0 {
			ret += i
		}
	}

	return ret
}

func Classify(n int64) (Classification, error) {
	if n <= 0 {
		return ClassificationAbundant, ErrOnlyPositive
	}

	sum := sumOfDivisors(n)
	switch {
	case sum == n:
		return ClassificationPerfect, nil
	case sum > n:
		return ClassificationAbundant, nil
	case sum < n:
		return ClassificationDeficient, nil
	default:
		panic("never reach here")
	}
}
