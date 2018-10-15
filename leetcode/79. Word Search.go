/*
79. Word Search


Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/

func exist(board [][]byte, word string) bool {
	if len(word) == 0 || len(board)*len(board[0]) < len(word) {
		return false
	}
	boolarray := make([][]bool, len(board))
	for i := 0; i < len(boolarray); i++ {
		boolarray[i] = make([]bool, len(board[i]))
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if backTrack(board, boolarray, i, j, word) {
				return true
			}
		}
	}
	return false
}

func backTrack(board [][]byte, boolarray [][]bool, row, col int, s string) bool {
	if len(s) == 0 {
		return true
	}
	if row < 0 || row >= len(board) || col < 0 || col >= len(board[0]) {
		return false
	}
	if boolarray[row][col] || board[row][col] != s[0] {
		return false
	}

	boolarray[row][col] = true
	res := backTrack(board, boolarray, row+1, col, s[1:]) || backTrack(board, boolarray, row-1, col, s[1:]) ||
		backTrack(board, boolarray, row, col-1, s[1:]) || backTrack(board, boolarray, row, col+1, s[1:])
	boolarray[row][col] = false
	return res
}