/*
12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"

Example 4:

Input: 58
Output: "LVIII"
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

func intToRoman(num int) string {
	//translate the digits into strings
	strSlice := make([]string, 0)
	for i := 0; num != 0; i++ {
		if i == 0 {
			strSlice = append(strSlice, digitToRoman(num%10, 'I', 'V', 'X'))
		}
		if i == 1 {
			strSlice = append(strSlice, digitToRoman(num%10, 'X', 'L', 'C'))
		}
		if i == 2 {
			strSlice = append(strSlice, digitToRoman(num%10, 'C', 'D', 'M'))
		}
		if i == 3 {
			strSlice = append(strSlice, digitToRoman(num%10, 'M', ' ', ' '))
		}
		num /= 10
	}
	//join the elements of strslice by reserve order
	res := ""
	for i := len(strSlice) - 1; i >= 0; i-- {
		res += strSlice[i]
	}
	return res
}

//translate the common digit to roman digit
func digitToRoman(num int, b1, b2, b3 byte) string {
	strSlice := make([]byte, 0)
	switch num % 10 {
	case 1, 2, 3:
		for i := 0; i < num%10; i++ {
			strSlice = append(strSlice, b1)
		}
	case 4:
		strSlice = append(strSlice, b1)
		strSlice = append(strSlice, b2)
	case 5:
		strSlice = append(strSlice, b2)
	case 6, 7, 8:
		strSlice = append(strSlice, b2)
		for i := 5; i < num%10; i++ {
			strSlice = append(strSlice, b1)
		}
	case 9:
		strSlice = append(strSlice, b1)
		strSlice = append(strSlice, b3)
	}
	return string(strSlice)
}