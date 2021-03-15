package brackets

func Bracket(input string) bool {
	var stack []rune
	pair := map[rune]rune{
		'}': '{',
		']': '[',
		')': '(',
	}

	for _, c := range input {
		switch c {
		case '{', '[', '(':
			stack = append(stack, c)
		case '}', ']', ')':
			if len(stack) == 0 {
				return false
			}

			last := stack[len(stack)-1]
			if last != pair[c] {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}

	return len(stack) == 0
}
