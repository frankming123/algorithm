/*
29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

func divide(dividend int, divisor int) int {
	if dividend == -2147483648 && divisor == -1 {
		return 2147483647
	}
	quotient := 0
	isNag := false
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		isNag = true
	}
	dividend = abs(dividend)
	divisor = abs(divisor)
	for dividend >= divisor {
		dividend -= divisor
		quotient++
	}
	if isNag {
		return -quotient
	}
	return quotient
}

func abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}