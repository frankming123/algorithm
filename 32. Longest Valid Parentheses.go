/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"

Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"

Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

func longestValidParentheses(s string) int {
	res := 0
	stack := make([]int, 1)
	stack[0] = -1
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, i)
		}
		if s[i] == ')' {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
				continue
			} else {
				res = max(res, i-stack[len(stack)-1])
			}
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}