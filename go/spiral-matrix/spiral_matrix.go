package spiralmatrix

const (
	right = iota
	down
	left
	up
)

func SpiralMatrix(n int) [][]int {
	if n == 0 {
		return [][]int{}
	}

	ret := make([][]int, n)
	for i := 0; i < n; i++ {
		ret[i] = make([]int, n)
		for j := 0; j < n; j++ {
			ret[i][j] = 0
		}
	}

	way := right

	x := 0
	y := 0
	ret[0][0] = 1
	count := 2
	limit := n * n
	for {
		if count > limit {
			break
		}

		switch way {
		case right:
			if y+1 < n && ret[x][y+1] == 0 {
				y++
				ret[x][y] = count
				count++
			} else {
				way = down
			}
		case down:
			if x+1 < n && ret[x+1][y] == 0 {
				x++
				ret[x][y] = count
				count++
			} else {
				way = left
			}
		case left:
			if y-1 >= 0 && ret[x][y-1] == 0 {
				y--
				ret[x][y] = count
				count++
			} else {
				way = up
			}
		case up:
			if x-1 >= 0 && ret[x-1][y] == 0 {
				x--
				ret[x][y] = count
				count++
			} else {
				way = right
			}
		}
	}

	return ret
}
