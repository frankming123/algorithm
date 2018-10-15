/*
120. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

func minimumTotal(triangle [][]int) int {
	tlen := len(triangle)
	path := make([]int, len(triangle[tlen-1]))
	for i := 0; i < len(path); i++ {
		path[i] = triangle[tlen-1][i]
	}

	for i := tlen - 2; i >= 0; i-- {
		for k := 0; k < len(triangle[i]); k++ {
			path[k] = min(path[k], path[k+1]) + triangle[i][k]
		}
	}
	return path[0]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}