/*
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its depth = 3.
*/

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := []*TreeNode{root}
	depth := 0
	for len(queue) != 0 {
		qlen := len(queue)
		for i := 0; i < qlen; i++ {
			node := queue[i]
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}
		queue = queue[qlen:]
		depth++
	}
	return depth
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + usefulfuncs.Max(maxDepth(root.Left), maxDepth(root.Right))
}