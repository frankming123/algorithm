/*
70. Climbing Stairs


You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2

Output: 2

Explanation: There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3

Output: 3

Explanation: There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

//use backTracking
func climbStairs(n int) int {
	res := 0
	backTrack(n, &res)
	return res
}

func backTrack(remain int, count *int) {
	if remain == 0 {
		*count++
		return
	}

	if remain >= 2 {
		backTrack(remain-2, count)
	}
	backTrack(remain-1, count)
}

//use dynamic programming
func climbStairs(n int) int {
	if n == 1 {
		return 1
	}
	counts := make([]int, n)
	counts[0] = 1
	counts[1] = 2
	for i := 2; i < n; i++ {
		counts[i] = counts[i-1] + counts[i-2]
	}
	return counts[n-1]
}

//use DFS
func climbStairs(n int) int {
	count := 0
	stack := []int{}
	stack = append(stack, 0)
	for len(stack) != 0 {
		pop := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if pop == n {
			count++
		} else {
			stack = append(stack, pop+1)
			if n-pop >= 2 {
				stack = append(stack, pop+2)
			}
		}
	}
	return count
}