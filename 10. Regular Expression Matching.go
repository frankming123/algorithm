/*
10. Regular Expression Matching

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

//wrong error-.- I need time to fix it
func isMatch(s string, p string) bool {
	sLen, pLen := len(s), len(p)
	var i, j int

	for j < pLen {
		if i == sLen {
			if j+1 < pLen && p[j+1] == '*' {
				j++
				continue
			} else {
				return false
			}
		}

		switch {
		case p[j] >= 'a' && p[j] <= 'z':
			if j+1 < pLen && p[j+1] == '*' {
				if j+2 < pLen && p[j+2] == p[j] {
					if s[i] == p[j+2] {
						pInd := endIndexOfContinuousRepeatChar(p, j+2)
						sInd := endIndexOfContinuousRepeatChar(s, i)

						if pInd-j-2 <= sInd-i {
							i = sInd + 1
							j = pInd
						} else {
							return false
						}
					} else {
						return false
					}
				} else {
					for i != sLen && s[i] == p[j] {
						i++
					}
					j++
				}
			} else if p[j] != s[i] {
				return false
			} else {
				i++
			}

		case p[j] == '.':
			if j+1 < pLen && p[j+1] == '*' {
				for i != sLen {
					i++
				}
				j++
			} else {
				i++
			}
		default:
			return false
		}
		j++
	}

	if i != sLen {
		return false
	}

	return true
}

func endIndexOfContinuousRepeatChar(s string, ind int) int {
	char := s[ind]
	i := ind
	for i+1 < len(s) {
		if s[i+1] != char {
			break
		}
		i++
	}

	return i
}
