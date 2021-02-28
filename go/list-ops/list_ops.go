package listops

type IntList []int
type predFunc func(n int) bool
type binFunc func(x, y int) int
type unaryFunc func(n int) int

func (lst IntList) Filter(f predFunc) IntList {
	ret := make(IntList, 0)
	for _, n := range lst {
		if f(n) {
			ret = append(ret, n)
		}
	}

	return ret
}

func (lst IntList) Length() int {
	return len(lst)
}

func (lst IntList) Map(f unaryFunc) IntList {
	ret := make(IntList, 0)
	for _, n := range lst {
		ret = append(ret, f(n))
	}

	return ret
}

func (lst IntList) Reverse() IntList {
	ret := make(IntList, len(lst))
	i := 0
	j := len(lst) - 1

	for i < j {
		ret[i], ret[j] = lst[j], lst[i]
		i++
		j--
	}

	return ret
}

func (lst IntList) Append(other IntList) IntList {
	ret := make(IntList, len(lst))
	copy(ret, lst)

	for _, n := range other {
		ret = append(ret, n)
	}

	return ret
}

func (lst IntList) Concat(a []IntList) IntList {
	ret := make(IntList, len(lst))
	copy(ret, lst)

	for _, v := range a {
		for _, n := range v {
			ret = append(ret, n)
		}
	}

	return ret
}

func (lst IntList) Foldl(f binFunc, val int) int {
	ret := val

	for _, n := range lst {
		ret = f(ret, n)
	}

	return ret
}

func (lst IntList) Foldr(f binFunc, val int) int {
	if len(lst) == 0 {
		return val
	}

	v := lst[1:].Foldr(f, val)
	return f(lst[0], v)
}
