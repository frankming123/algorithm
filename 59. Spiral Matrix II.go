/*
59. Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3

Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

func generateMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	count := 0
	for i := 0; i < (n+1)/2; i++ {
		for j := i; j < n-i; j++ {
			count++
			matrix[i][j] = count
		}
		for j := i + 1; j < n-i-1; j++ {
			count++
			matrix[j][n-i-1] = count
		}
		if n-1-i != i {
			for j := n - i - 1; j >= i; j-- {
				count++
				matrix[n-1-i][j] = count
			}
		}
		for j := n - i - 2; j > i; j-- {
			count++
			matrix[j][i] = count
		}
	}
	return matrix
}