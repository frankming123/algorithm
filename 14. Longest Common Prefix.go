/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:

All given inputs are in lowercase letters a-z.
*/

func longestCommonPrefix(strs []string) string {
	if len(strs) == 1 {
		return strs[0]
	}
	if len(strs) == 0 {
		return ""
	}
	comp := longestCommonPrefixOfTwoString(strs[0], strs[1])
	for i := 2; i < len(strs); i++ {
		comp = longestCommonPrefixOfTwoString(comp, strs[i])
		if comp == "" {
			return ""
		}
	}
	return comp
}

func longestCommonPrefixOfTwoString(s1, s2 string) string {
	min := len(s1)
	res := make([]byte, 0)

	if min > len(s2) {
		min = len(s2)
	}

	for i := 0; i < min && s1[i] == s2[i]; i++ {
		res = append(res, s1[i])
	}

	return string(res)
}