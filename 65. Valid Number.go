/*
65. Valid Number

Validate if a given string is numeric.

Some examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):

The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
*/

//according to the Discuss, it is not a good problem-.-
func isNumber(s string) bool {
	s = strings.Trim(s, " ")
	if len(s) == 0 {
		return false
	}
	if s[0] == '-' || s[0] == '+' {
		s = s[1:]
	}
	var isInt, isFloat, isE, isAfterE bool
	for i := 0; i < len(s); i++ {
		if s[i] >= '0' && s[i] <= '9' {
			if isE {
				isAfterE = true
			}
			isInt = true
		} else if s[i] == '.' {
			if !isFloat && !isE {
				isFloat = true
			} else {
				return false
			}
		} else if s[i] == 'e' {
			if !isE && i != 0 && isInt {
				isE = true
			} else {
				return false
			}
		} else if i > 0 && s[i-1] == 'e' && (s[i] == '-' || s[i] == '+') {

		} else {
			return false
		}
	}

	return (isE && isAfterE) || (!isE && isFloat && isInt) || (!isE && !isFloat && isInt)
}