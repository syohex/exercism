package isogram

import "strings"

func IsIsogram(s string) bool {
	str := strings.ToLower(s)
	var table [26]int

	for _, c := range str {
		if !(c >= 'a' && c <= 'z') {
			continue
		}

		index := byte(c) - 'a'
		if table[index] != 0 {
			return false
		}

		table[index]++
	}

	return true
}
