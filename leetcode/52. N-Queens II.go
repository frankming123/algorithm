/*
52. N-Queens II

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4

Output: 2

Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

//just like the problem before...
func totalNQueens(n int) int {
	res := 0
	puzzle := make([][]byte, n)
	for i := 0; i < n; i++ {
		row := make([]byte, n)
		for j := 0; j < n; j++ {
			row[j] = '.'
		}
		puzzle[i] = row
	}
	backTrack(puzzle, &res, 0, n)
	return res
}

func backTrack(puzzle [][]byte, res *int, start, remain int) {
	if remain == 0 {
		*res++
		return
	}
	pLen := len(puzzle)

	for i := start; i < pLen*pLen; i++ {
		row := i / pLen
		col := i % pLen

		if isRight(puzzle, row, col) {
			puzzle[row][col] = 'Q'
			backTrack(puzzle, res, i-col+pLen, remain-1)
			puzzle[row][col] = '.'
		}
	}
}

func isRight(puzzle [][]byte, row, col int) bool {
	pLen := len(puzzle)
	for i := 0; i < pLen; i++ {
		if puzzle[row][i] == 'Q' || puzzle[i][col] == 'Q' ||
			(row+col-i < pLen && row+col-i >= 0 && puzzle[i][row+col-i] == 'Q') ||
			(col-row >= 0 && i+col-row < pLen && puzzle[i][i+col-row] == 'Q') ||
			(row-col > 0 && i+row-col < pLen && puzzle[i+row-col][i] == 'Q') {
			return false
		}
	}
	return true
}