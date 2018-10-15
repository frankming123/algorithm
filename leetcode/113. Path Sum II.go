/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return [][]int{}
	}
	res := [][]int{}
	backTrack(root, sum, []int{root.Val}, &res)
	return res
}

func backTrack(root *TreeNode, remain int, nums []int, res *[][]int) {
	if root == nil {
		return
	}
	if remain == root.Val && root.Left == nil && root.Right == nil {
		cpy := make([]int, len(nums))
		copy(cpy, nums)
		*res = append(*res, cpy)
		return
	}

	if root.Left != nil {
		nums = append(nums, root.Left.Val)
		backTrack(root.Left, remain-root.Val, nums, res)
		nums = nums[:len(nums)-1]
	}

	if root.Right != nil {
		nums = append(nums, root.Right.Val)
		backTrack(root.Right, remain-root.Val, nums, res)
		nums = nums[:len(nums)-1]
	}
}