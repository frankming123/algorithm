/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

func solveSudoku(board [][]byte) {
	solve(board, 0)
}

//use backtracking
func solve(board [][]byte, pos int) bool {
	if pos == 81 {
		return true
	}
	row := pos / 9
	col := pos % 9

	if board[row][col] != '.' {
		return solve(board, pos+1)
	}

	var c byte
	for c = '1'; c <= '9'; c++ {
		if isValid(board, row, col, c) {
			board[row][col] = c
			if solve(board, pos+1) {
				return true
			} else {
				board[row][col] = '.'
			}
		}
	}
	return false
}

//check if such number is correct
func isValid(board [][]byte, row, col int, c byte) bool {
	for i := 0; i < 9; i++ {
		if board[row][i] != '.' && board[row][i] == c {
			return false
		}
		if board[i][col] != '.' && board[i][col] == c {
			return false
		}
		if board[row-row%3+i/3][col-col%3+i%3] != '.' && board[row-row%3+i/3][col-col%3+i%3] == c {
			return false
		}
	}
	return true
}