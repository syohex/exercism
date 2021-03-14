package accumulate

func Accumulate(args []string, f func(string) string) []string {
	var ret []string
	for _, arg := range args {
		ret = append(ret, f(arg))
	}

	return ret
}
