/*
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"

Output: 5
*/

func lengthOfLastWord(s string) int {
	//trim the right space
	i := len(s) - 1
	for i >= 0 && s[i] == ' ' {
		i--
	}
	s = s[:i+1]
	//count the word from right to left
	count := 0
	for i := len(s) - 1; i >= 0 && s[i] != ' '; i-- {
		count++
	}
	return count
}