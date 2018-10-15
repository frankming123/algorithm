/*
64. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

Output: 7

Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

//use DP Solution
func minPathSum(grid [][]int) int {
	rLen := len(grid)
	cLen := len(grid[0])
	path := make([][]int, rLen)
	for i := 0; i < rLen; i++ {
		path[i] = make([]int, cLen)
		for j := 0; j < cLen; j++ {
			path[i][j] = grid[i][j]
		}
	}

	for i := 1; i < rLen; i++ {
		path[i][0] = path[i-1][0] + path[i][0]
	}
	for i := 1; i < cLen; i++ {
		path[0][i] = path[0][i-1] + path[0][i]
	}

	for i := 1; i < rLen; i++ {
		for j := 1; j < cLen; j++ {
			path[i][j] = usefulfuncs.Min(path[i-1][j], path[i][j-1]) + path[i][j]
		}
	}
	return path[rLen-1][cLen-1]
}