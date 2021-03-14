package change

import (
	"fmt"
	"math"
	"sort"
)

func Change(coins []int, target int) ([]int, error) {
	type data struct {
		count int
		coins []int
	}

	if target == 0 {
		return []int{}, nil
	}
	if target < 0 {
		return nil, fmt.Errorf("negative target")
	}

	dp := make([]data, target+1)
	for i := 0; i <= target; i++ {
		dp[i].count = math.MaxInt32
		dp[i].coins = []int{}
	}

	dp[0].count = 0

	for i := 1; i <= target; i++ {
		for _, coin := range coins {
			if i >= coin {
				prev := dp[i-coin]
				if prev.count+1 < dp[i].count {
					dp[i].count = prev.count + 1

					tmp := make([]int, len(prev.coins))
					copy(tmp, prev.coins)
					tmp = append(tmp, coin)
					dp[i].coins = tmp
				}
			}
		}
	}

	if len(dp[target].coins) == 0 {
		return nil, fmt.Errorf("no answer")
	}

	sort.Slice(dp[target].coins, func(i int, j int) bool {
		return dp[target].coins[i] < dp[target].coins[j]
	})

	return dp[target].coins, nil
}
