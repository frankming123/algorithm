/*
62. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2

Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3

Output: 28
*/
type tuple struct {
	m int
	n int
}

//approach1, use dfs but Time Limit Exceeded
func uniquePaths(m int, n int) int {
	stack := make([]tuple, 0)
	count := 0
	stack = append(stack, tuple{m - 1, n - 1})
	for len(stack) != 0 {
		tmp := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		tmpM := tmp.m
		tmpN := tmp.n
		if tmpM == 0 && tmpN == 0 {
			count++
		} else if tmpM == 0 {
			stack = append(stack, tuple{tmpM, tmpN - 1})
		} else if tmpN == 0 {
			stack = append(stack, tuple{tmpM - 1, tmpN})
		} else {
			stack = append(stack, tuple{tmpM, tmpN - 1})
			stack = append(stack, tuple{tmpM - 1, tmpN})
		}
	}
	return count
}

//approach2, use backtrack but Time Limit Exceeded
func uniquePaths(m int, n int) int {
	count := 0
	backTrack(m-1, n-1, m-1, n-1, &count)
	return count
}

func backTrack(m, n, mremain, nremain int, count *int) {
	if mremain == 0 && nremain == 0 {
		*count++
		return
	}

	if mremain != 0 {
		backTrack(m, n, mremain-1, nremain, count)
	}
	if nremain != 0 {
		backTrack(m, n, mremain, nremain-1, count)
	}

}

//approach3, use DP Solution
func uniquePaths(m int, n int) int {
	path := make([][]int, m)
	for i := 0; i < m; i++ {
		path[i] = make([]int, n)
		for j := 0; j < n; j++ {
			path[i][j] = 1
		}
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			path[i][j] = path[i-1][j] + path[i][j-1]
		}
	}
	return path[m-1][n-1]
}