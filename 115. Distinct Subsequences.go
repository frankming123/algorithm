/*
115. Distinct Subsequences

Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3

Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5

Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
	^^^
*/

//use backtrack, but time limit exceeded
func numDistinct(s string, t string) int {
	count := 0
	backTrack(s, t, &count)
	return count
}

func backTrack(s string, t string, count *int) {
	if len(t) == 0 {
		*count++
		return
	}
	if len(s) == 0 {
		return
	}

	if s[0] == t[0] {
		backTrack(s[1:], t[1:], count)
	}
	backTrack(s[1:], t, count)
}

//use dynamic programming, faster
func numDistinct(s string, t string) int {
	path := make([][]int, len(t)+1)
	for i := 0; i <= len(t); i++ {
		path[i] = make([]int, len(s)+1)
	}
	for i := 0; i <= len(s); i++ {
		path[0][i] = 1
	}

	for i := 0; i < len(t); i++ {
		for j := 0; j < len(s); j++ {
			if t[i] == s[j] {
				path[i+1][j+1] = path[i][j] + path[i+1][j]
			} else {
				path[i+1][j+1] = path[i+1][j]
			}
		}
	}
	return path[len(t)][len(s)]
}