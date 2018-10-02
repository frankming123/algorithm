/*
125. Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

func isPalindrome(s string) bool {
	str := []byte{}
	for _, v := range s {
		if v >= 'A' && v <= 'Z' {
			str = append(str, byte('a'-'A'+v))
		} else if (v >= 'a' && v <= 'z') || (v >= '0' && v <= '9') {
			str = append(str, byte(v))
		}
	}
	for i := 0; i < len(str)/2; i++ {
		if str[i] != str[len(str)-i-1] {
			return false
		}
	}
	return true
}
