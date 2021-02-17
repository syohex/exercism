package reverse

func Reverse(str string) string {
	if len(str) == 0 {
		return ""
	}

	var ret []rune
	rs := []rune(str)
	for i := len(rs) - 1; i >= 0; i -= 1 {
		ret = append(ret, rs[i])
	}

	return string(ret)
}
