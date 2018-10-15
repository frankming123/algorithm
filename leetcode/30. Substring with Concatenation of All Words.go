/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]

Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]

Output: []
*/

func findSubstring(s string, words []string) []int {
	//return if illegal parameters
	if len(s) == 0 || len(words) == 0 {
		return []int{}
	}
	if len(words[0]) == 0 {
		return []int{0}
	}
	//wordMap: contains words in array:words, which key is its count
	wordMap := make(map[string]int)
	wLen := len(words[0])
	res := make([]int, 0)
	for i := 0; i < len(words); i++ {
		if _, ok := wordMap[words[i]]; !ok {
			wordMap[words[i]] = 1
		} else {
			wordMap[words[i]]++
		}
    }
    
	for i := 0; i <= len(s)-wLen*len(words); i++ {
        //copy map:wordMap deeply
		tmpMap := make(map[string]int)
		for k, v := range wordMap {
			tmpMap[k] = v
		}
        //if s contains substring which map:tmpMap has, minus its count until 0
		for j := 0; j < len(words); j++ {
			str := s[i+j*wLen : i+j*wLen+wLen]
			if v, ok := tmpMap[str]; ok {
				if v == 1 {
					delete(tmpMap, str)
				} else {
					tmpMap[str]--
				}
			} else {
				break
			}
		}
		if len(tmpMap) == 0 {
			res = append(res, i)
		}
	}
	return res
}