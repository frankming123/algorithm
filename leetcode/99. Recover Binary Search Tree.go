/*
99. Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var firstNode *TreeNode
var secondNode *TreeNode
var prevNode *TreeNode = &TreeNode{-1 << 63, nil, nil}

func recoverTree(root *TreeNode) {
	traverse(root)
	firstNode.Val, secondNode.Val = secondNode.Val, firstNode.Val
}

func traverse(root *TreeNode) {
	if root == nil {
		return
	}
	traverse(root.Left)
	if firstNode == nil && prevNode.Val >= root.Val {
		firstNode = prevNode
	}
	if firstNode != nil && prevNode.Val >= root.Val {
		secondNode = root
	}
	prevNode = root
	traverse(root.Right)
}