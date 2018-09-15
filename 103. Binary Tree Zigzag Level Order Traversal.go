/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:

Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	res := levelOrder(root)
	for i := 1; i < len(res); i += 2 {
		nums := res[i]
		for j := 0; j < len(nums)/2; j++ {
			nums[j], nums[len(nums)-1-j] = nums[len(nums)-1-j], nums[j]
		}
	}
	return res
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res := [][]int{}
	queue := []*TreeNode{root}
	count := 0
	cut := 0
	for len(queue) != 0 {
		if count <= 0 {
			if len(res) == 0 {
				count = 1
			} else {
				count = len(res[len(res)-1])*2 - cut
			}
			res = append(res, []int{})
			cut = 0
		}
		node := queue[0]
		queue = queue[1:]

		res[len(res)-1] = append(res[len(res)-1], node.Val)
		count--

		if node.Left != nil {
			queue = append(queue, node.Left)
		} else {
			cut++
		}
		if node.Right != nil {
			queue = append(queue, node.Right)
		} else {
			cut++
		}
	}
	return res
}