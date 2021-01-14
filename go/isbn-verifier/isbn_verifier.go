package isbn

func IsValidISBN(isbn string) bool {
	s := ""
	for i, r := range isbn {
		c := int(r)
		if c >= int('0') && c <= int('9') || (i == len(isbn)-1 && c == 'X') {
			s += string(r)
		}
	}

	if len(s) != 10 {
		return false
	}

	sum := 0
	for i, c := range s {
		if c == 'X' {
			sum += (10 - i) * 10
		} else {
			sum += (10 - i) * (int(c) - int('0'))
		}
	}

	return sum%11 == 0
}
