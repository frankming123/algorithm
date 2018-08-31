/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"

Output: "100"

Example 2:

Input: a = "1010", b = "1011"

Output: "10101"
*/

func addBinary(a string, b string) string {
	res := make([]byte, 0)
	alen := len(a)
	blen := len(b)
	addNum := 0
	maxlen := max(alen, blen)

	for i := 0; i < maxlen; i++ {
		var avar, bvar byte
		if alen-1-i < 0 {
			avar = '0'
		} else {
			avar = a[alen-1-i]
		}
		if blen-1-i < 0 {
			bvar = '0'
		} else {

			bvar = b[blen-1-i]
		}
		tmp := avar - '0' + bvar + byte(addNum)
		if tmp > '1' {
			addNum = 1
			tmp -= 2
		} else {
			addNum = 0
		}
		res = append(res, tmp)
	}

	if addNum == 1 {
		res = append(res, '1')
	}

	for i:=0;i<len(res)/2;i++{
		res[i],res[len(res)-i-1]=res[len(res)-i-1],res[i]
	}

	return string(res)
}

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}