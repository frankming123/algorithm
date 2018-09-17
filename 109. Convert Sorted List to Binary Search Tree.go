/*
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	count := 0
	for node := head; node != nil; node = node.Next {
		count++
	}
	return helper(head, count)
}

func helper(head *ListNode, length int) *TreeNode {
	if length == 0 {
		return nil
	}
	mid := length / 2
	root := &TreeNode{0, nil, nil}
	node := head
	for i := 0; i < mid; i++ {
		node = node.Next
	}
	root.Val = node.Val
	root.Left = helper(head, mid)
	root.Right = helper(node.Next, length-mid-1)
	return root
}