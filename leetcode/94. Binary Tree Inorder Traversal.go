/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	backTrack(root, &res)
	return res
}

func backTrack(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	if root.Left != nil {
		backTrack(root.Left, res)
	}
	*res = append(*res, root.Val)
	if root.Right != nil {
		backTrack(root.Right, res)
	}
}