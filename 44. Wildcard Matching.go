/*
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.

Example 1:

Input:
s = "aa"
p = "a"

Output: false

Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "*"

Output: true

Explanation: '*' matches any sequence.

Example 3:

Input:
s = "cb"
p = "?a"

Output: false

Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:

Input:
s = "adceb"
p = "*a*b"

Output: true

Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:

Input:
s = "acdcb"
p = "a*c?b"

Output: false
*/

//It is right but exceeding the time limit...
func isMatch(s string, p string) bool {
	if len(p) == 0 {
		return len(s) == 0
	}

	if p[0] == '*' {
		return isMatch(s, p[1:]) || (len(s) > 0 && isMatch(s[1:], p))
	} else if len(s) > 0 && (p[0] == '?' || p[0] == s[0]) {
		return isMatch(s[1:], p[1:])
	} else {
		return false
	}
}

//use dynamic programming with 2D table
func isMatch(s string, p string) bool {
	if p == "" {
		return s == ""
	}
	if s == "" {
		for i := 0; i < len(p); i++ {
			if p[i] != '*' {
				return false
			}
		}
		return true
	}
	dp := make([][]bool, len(s)+1)
	for i := 0; i < len(s)+1; i++ {
		dp[i] = make([]bool, len(p)+1)
	}
	dp[0][0] = true
	for i := 1; i < len(dp[0]) && p[i-1] == '*'; i++ {
		dp[0][i] = true
	}

	for i := 1; i < len(dp); i++ {
		for j := 1; j < len(dp[0]); j++ {
			str := s[i-1]
			pattern := p[j-1]
			if str == pattern || pattern == '?' {
				dp[i][j] = dp[i-1][j-1]
			} else if pattern == '*' {
				dp[i][j] = dp[i-1][j] || dp[i][j-1]
			}
		}
	}

	return dp[len(s)][len(p)]
}