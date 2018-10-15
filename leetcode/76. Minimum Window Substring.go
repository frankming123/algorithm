/*
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"

Output: "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

//this problem is so hard that I copy the answer first, then try to understand it.
func minWindow(s string, t string) string {
	if len(s) == 0 || len(t) == 0 {
		return ""
	}

	tmap := make(map[rune]int)
	for _, v := range t {
		if _, ok := tmap[v]; ok {
			tmap[v]++
		} else {
			tmap[v] = 1
		}
	}

	required := len(tmap)
	l, r := 0, 0
	formed := 0

	windowmap := make(map[rune]int)
	ans := []int{-1, 0, 0}

	for r < len(s) {
		c := rune(s[r])
		if _, ok := windowmap[c]; ok {
			windowmap[c]++
		} else {
			windowmap[c] = 1
		}

		if _, ok := tmap[c]; ok && windowmap[c] == tmap[c] {
			formed++
		}

		for l <= r && formed == required {
			c = rune(s[l])
			if ans[0] == -1 || r-l+1 < ans[0] {
				ans[0] = r - l + 1
				ans[1] = l
				ans[2] = r
			}
			windowmap[c]--
			if _, ok := tmap[c]; ok && windowmap[c] < tmap[c] {
				formed--
			}
			l++
		}
		r++
	}
	if ans[0] == -1 {
		return ""
	}
	return s[ans[1] : ans[2]+1]
}