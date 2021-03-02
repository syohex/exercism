package strain

type Ints []int
type Strings []string
type Lists [][]int

func (v Ints) Keep(f func(int) bool) Ints {
	var ret Ints
	for _, e := range v {
		if f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}

func (v Ints) Discard(f func(int) bool) Ints {
	var ret Ints
	for _, e := range v {
		if !f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}

func (v Strings) Keep(f func(string) bool) Strings {
	var ret Strings
	for _, e := range v {
		if f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}

func (v Strings) Discard(f func(string) bool) Strings {
	var ret Strings
	for _, e := range v {
		if !f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}

func (v Lists) Keep(f func([]int) bool) Lists {
	var ret Lists
	for _, e := range v {
		if f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}

func (v Lists) Discard(f func([]int) bool) Lists {
	var ret Lists
	for _, e := range v {
		if !f(e) {
			ret = append(ret, e)
		}
	}

	return ret
}
