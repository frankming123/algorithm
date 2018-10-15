/*
54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]

Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

func spiralOrder(matrix [][]int) []int {
	res := make([]int, 0)
	for len(matrix) > 0 {
		res = append(res, oneRound(matrix)...)
		if len(matrix) < 3 || len(matrix[0]) < 3 {
			break
		}
		matrix = matrix[1 : len(matrix)-1]
		for i := 0; i < len(matrix); i++ {
			matrix[i] = matrix[i][1 : len(matrix[i])-1]
		}
	}
	return res
}

func oneRound(matrix [][]int) []int {
	rLen := len(matrix)
	cLen := len(matrix[0])
	res := make([]int, 0)

	for i := 0; i < cLen; i++ {
		res = append(res, matrix[0][i])
	}
	for i := 1; i < rLen; i++ {
		res = append(res, matrix[i][cLen-1])
	}
	if rLen > 1 {
		for i := 1; i < cLen; i++ {
			res = append(res, matrix[rLen-1][cLen-i-1])
		}
	}
	if cLen > 1 {
		for i := 1; i < rLen-1; i++ {
			res = append(res, matrix[rLen-i-1][0])
		}
	}

	return res
}