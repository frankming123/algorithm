/*
72. Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"

Output: 3

Explanation: 

horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"

Output: 5

Explanation: 

intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

//use dynamic programming
func minDistance(word1 string, word2 string) int {
	dparray := make([][]int, len(word1)+1)
	for i := 0; i <= len(word1); i++ {
		dparray[i] = make([]int, len(word2)+1)
		dparray[i][0] = i
	}
	for i := 0; i <= len(word2); i++ {
		dparray[0][i] = i
	}

	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			if word1[i-1] == word2[j-1] {
				dparray[i][j] = dparray[i-1][j-1]
			} else {
				dparray[i][j] = min(dparray[i][j-1], min(dparray[i-1][j-1], dparray[i-1][j])) + 1
			}
		}
	}
	return dparray[len(word1)][len(word2)]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}