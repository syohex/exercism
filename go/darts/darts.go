package darts

import (
	"math"
)

func Score(x float64, y float64) int {
	v := math.Sqrt(x*x + y*y)

	switch {
	case v <= 1.0:
		return 10
	case v > 1.0 && v <= 5.0:
		return 5
	case v > 5.0 && v <= 10.0:
		return 1
	default:
		return 0
	}
}
