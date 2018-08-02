/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"
*/

//Approach: Expand Around Center
func longestPalindrome(s string) string {
	var res string
	for i := 0; i < len(s); i++ {
		max1 := extendChar(s, i, i)
		max2 := extendChar(s, i, i+1)
		charMax := max(max1, max2)
		if len(res) < charMax {
			left := i - (charMax-1)/2
			right := i + charMax/2
			println(left, right)
			res = s[left : right+1]
		}
	}
	return res
}

//given the index, then expand around center until its longest length to be palindromic
func extendChar(s string, left, right int) int {
	charLen := 1
	for left >= 0 && right < len(s) {
		if s[left] != s[right] {
			break
		}
		charLen = right - left + 1
		left--
		right++
	}
	return charLen
}

//max()
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}