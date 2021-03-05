package rotationalcipher

func RotationalCipher(input string, shift int) string {
	var ret []byte
	bs := []byte(input)
	for _, b := range bs {
		if b >= 'a' && b <= 'z' {
			ret = append(ret, ((b-'a'+byte(shift))%26)+'a')
		} else if b >= 'A' && b <= 'Z' {
			ret = append(ret, ((b-'A'+byte(shift))%26)+'A')
		} else {
			ret = append(ret, b)
		}
	}

	return string(ret)
}
