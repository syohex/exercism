package hamming

import "fmt"

func Distance(a, b string) (int, error) {
	if len(a) != len(b) {
		return 0, fmt.Errorf("arguments must be same size")
	}

	ret := 0
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			ret++
		}
	}

	return ret, nil
}
