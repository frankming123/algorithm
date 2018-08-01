func myAtoi(str string) int {
	//trim the space
	str = trimSpace(str)
	if len(str) == 0 {
		return 0
	}
	//judge the number: positive or negative
	ispos := false
	//the returned number
	res := 0
	//switch case
	switch {
	case str[0] == '+':
		ispos = true
		str = str[1:]
	case str[0] >= '0' && str[0] <= '9':
		ispos = true
	case str[0] == '-':
		str = str[1:]
	default:
		return 0
	}

	for i := 0; i < len(str); i++ {
		if str[i] > '9' || str[i] < '0' {
			break
		}
		res = res*10 + int(str[i]-'0')
		//extra check:avoid the number larger than 2^63
		if res > 2<<30 {
			res = 2 << 30
			break
		}
	}
	//make res negative if ispos is false
	if !ispos {
		res *= -1
	}
	//check:avoid the number larger than 2^31
	if res >= 2<<30 {
		return 2<<30 - 1
	} else {
		return res
	}
}

//function that trim the head space
func trimSpace(str string) string {
	for i := 0; i < len(str); i++ {
		if str[i] != ' ' {
			return str[i:]
		}
	}
	return ""
}
