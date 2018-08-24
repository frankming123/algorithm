/*
51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4

Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

//use backtrack
func solveNQueens(n int) [][]string {
	res := make([][]string, 0)
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

func backTrack(puzzle [][]byte, res *[][]string, start, remain int) {
	if remain == 0 {
		resPuzzle := make([]string, len(puzzle))
		for i := 0; i < len(puzzle); i++ {
			resPuzzle[i] = string(puzzle[i])
		}
		*res = append(*res, resPuzzle)

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