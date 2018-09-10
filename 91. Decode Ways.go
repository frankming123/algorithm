/*
91. Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

func numDecodings(s string) int {
	count := 0
	backTrack(s, &count)
	return count
}

func backTrack(s string, count *int) {
	if len(s) == 0 {
		*count++
		return
	}
	if s[0] != '0' {
		backTrack(s[1:], count)
	}
	if len(s) >= 2 && ((s[0] == '1') || (s[0] == '2' && s[1] <= '6')) {
		backTrack(s[2:], count)
	}
}