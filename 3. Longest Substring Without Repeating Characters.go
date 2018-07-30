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
