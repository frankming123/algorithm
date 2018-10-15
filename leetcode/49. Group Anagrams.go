/*
49. Group Anagrams

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],

Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

func groupAnagrams(strs []string) [][]string {
	res := make([][]string, 0)

	for len(strs) != 0 {
		sMap := make([]int, 26)
		sSlice := make([]string, 0)
		sSlice = append(sSlice, strs[0])
		for i := 0; i < len(strs[0]); i++ {
			sMap[strs[0][i]-'a']++
		}
		strs = strs[1:]
	loop:
		for i := 0; i < len(strs); i++ {
			cpyMap := make([]int, 26)
			for k, v := range sMap {
				cpyMap[k] = v
			}
			for j := 0; j < len(strs[i]); j++ {
				v := cpyMap[strs[i][j]-'a']

				if v == 0 {
					continue loop
				} else {
					cpyMap[strs[i][j]-'a']--
				}
			}
			isZero := true
			for i := 0; i < 26; i++ {
				if cpyMap[i] != 0 {
					isZero = false
					break
				}
			}
			if isZero {
				sSlice = append(sSlice, strs[i])
				strs = append(strs[:i], strs[i+1:]...)
				i--
			}
		}
		res = append(res, sSlice)
	}
	return res
}