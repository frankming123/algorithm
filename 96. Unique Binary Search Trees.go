/*
96. Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3

Output: 5

Explanation:

Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//dynamic programming
func numTrees(n int) int {
	path := make([]int, n+1)
	path[0] = 1
	for i := 1; i <= n; i++ {
		sum := 0
		for j := 1; j <= i; j++ {
			sum += path[j-1] * path[i-j]
		}
		path[i] = sum
	}
	return path[n]
}