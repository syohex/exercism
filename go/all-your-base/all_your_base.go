package allyourbase

import "fmt"

func ConvertToBase(inputBase int, digits []int, outBase int) ([]int, error) {
	if inputBase < 2 {
		return nil, fmt.Errorf("input base must be >= 2")
	}
	if outBase < 2 {
		return nil, fmt.Errorf("output base must be >= 2")
	}

	input := 0
	for _, n := range digits {
		if n < 0 || n >= inputBase {
			return nil, fmt.Errorf("all digits must satisfy 0 <= d < input base")
		}
		input = input*inputBase + n
	}

	if input == 0 {
		return []int{0}, nil
	}

	var ret []int
	for input > 0 {
		ret = append(ret, input%outBase)
		input /= outBase
	}

	i := 0
	j := len(ret) - 1
	for i < j {
		ret[j], ret[i] = ret[i], ret[j]
		i++
		j--
	}

	return ret, nil
}
