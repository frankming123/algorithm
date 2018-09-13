/*
97. Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/

func isInterleave(s1 string, s2 string, s3 string) bool {
	if len(s1) == 0 && len(s2) == 0 && len(s3) == 0 {
		return true
	}
	if len(s3) == 0 {
		return false
	}

	res := false
	if len(s1) != 0 && s1[0] == s3[0] {
		res = isInterleave(s1[1:], s2, s3[1:])
	}
	if len(s2) != 0 && s2[0] == s3[0] {
		res = res || isInterleave(s1, s2[1:], s3[1:])
	}
	return res
}