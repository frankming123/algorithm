/*
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.

The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:

matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

target = 3

Output: true

Example 2:

Input:

matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

target = 13

Output: false
*/

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	row := 0
	for i := 0; i < len(matrix) && matrix[i][0] <= target; i++ {
		row = i
	}
	for i := 0; i < len(matrix[0]); i++ {
		if matrix[row][i] == target {
			return true
		}
	}
	return false
}