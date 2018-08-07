/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

...

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	res := make([]string, 1)
	for i := 0; i < len(digits); i++ {
		num := ""
		switch digits[i] {
		case '2':
			num = "abc"
		case '3':
			num = "def"
		case '4':
			num = "ghi"
		case '5':
			num = "jkl"
		case '6':
			num = "mno"
		case '7':
			num = "pqrs"
		case '8':
			num = "tuv"
		case '9':
			num = "wxyz"
		}
		res = combinations(res, num)
	}

	return res
}

func combinations(strings []string, str string) []string {
	res := make([]string, 0)
	for i := 0; i < len(str); i++ {
		for _, v := range strings {
			res = append(res, v+string(str[i]))
		}
	}
	return res
}