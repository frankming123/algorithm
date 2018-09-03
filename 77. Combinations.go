/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2

Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

func combine(n int, k int) [][]int {
	res := make([][]int, 0)
	backTrack(&res, &[]int{}, 1, n, k)
	return res
}

func backTrack(combs *[][]int, comb *[]int, start, n, k int) {
	if k == 0 {
		cpy := make([]int, len(*comb))
		copy(cpy, *comb)
		*combs = append(*combs, cpy)
		return
	}
	for i := start; i <= n; i++ {
		*comb = append(*comb, i)
		backTrack(combs, comb, i+1, n, k-1)
		*comb = (*comb)[:len(*comb)-1]
	}
}