/*
38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1

Output: "1"

Example 2:

Input: 4

Output: "1211"
*/

func countAndSay(n int) string {
	res:="1"
	for i:=1;i<n;i++{
		res=sayNext(res)
	}
	return res
}

func sayNext(s string) string {
	res := ""
	c := s[0]
	count := 1
	for i := 1; i < len(s); i++ {
		if s[i] == c {
			count++
		} else {
			res += string(count+'0') + string(c)
			c = s[i]
			count = 1
		}
	}
	res += string(count+'0') + string(c)
	return res
}