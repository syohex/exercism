package flatten

func inner(ret []interface{}, input interface{}) []interface{} {
	switch t := input.(type) {
	case int:
		ret = append(ret, t)
	case []interface{}:
		for _, v := range t {
			ret = inner(ret, v)
		}
	}

	return ret
}

func Flatten(input interface{}) []interface{} {
	ret := make([]interface{}, 0)
	ret = inner(ret, input)
	return ret
}
