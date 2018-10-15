/*
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

//Optimized sliding window
func lengthOfLongestSubstring(s string) int {
	//smap:store bytes and their index
	smap := make(map[byte]int)
	//chars:store length of the longest substring
	chars := 0
	for i, j := 0, 0; j < len(s); j++ {
		//move left window when meet a repeated character
		if v, ok := smap[s[j]]; ok && i <= v {
			i = v + 1
		}
		//equal to: chars=max(chars,j-i+1)
		if chars < j-i+1 {
			chars = j - i + 1
		}
		//add, or update the new character s[j]
		smap[s[j]] = j
	}
	return chars
}
