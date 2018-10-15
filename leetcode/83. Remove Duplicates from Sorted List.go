/*
83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2

Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	header := &ListNode{0, head}
	left, node := head, head
	dup := head.Val
	for node.Next != nil {
		if node.Next.Val != dup {
			dup = node.Next.Val
			left.Next = node.Next
			left = left.Next

		}
		node = node.Next
	}
	if left != node {
		left.Next = node.Next
	}
	return header.Next
}