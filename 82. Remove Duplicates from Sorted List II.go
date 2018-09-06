/*
82. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	header := &ListNode{0, head}
	left, node := header, head
	dup := head.Val
	count := 1
	for node.Next != nil {
		if node.Next.Val == dup {
			count++
		} else {
			dup = node.Next.Val
			if count == 1 {
				left = node
			} else {
				left.Next = node.Next
			}
			count = 1
		}
		node = node.Next
	}
	if count > 1 {
		left.Next = node.Next
	}
	return header.Next
}