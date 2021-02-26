package queenattack

import (
	"fmt"
	"math"
)

func isValidPostion(pos string) bool {
	if len(pos) != 2 {
		return false
	}

	return pos[0] >= 'a' && pos[0] <= 'h' && pos[1] >= '1' && pos[1] <= '8'
}

func positionToIndex(pos string) (int, int) {
	x := pos[0] - 'a'
	y := pos[1] - '1'
	return int(x), int(y)
}

func CanQueenAttack(p1 string, p2 string) (bool, error) {
	if !(isValidPostion(p1) && isValidPostion(p2)) {
		return false, fmt.Errorf("invalid position string")
	}

	if p1 == p2 {
		return false, fmt.Errorf("same position")
	}

	x1, y1 := positionToIndex(p1)
	x2, y2 := positionToIndex(p2)

	if x1 == x2 || y1 == y2 {
		return true, nil
	}

	diffX := math.Abs(float64(x1 - x2))
	diffY := math.Abs(float64(y1 - y2))

	if diffX == diffY {
		return true, nil
	}

	return false, nil
}
