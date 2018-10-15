/*
92. Reverse Linked List II

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	head = &ListNode{0, head}
	node := head
	pos := 1
	for pos < m {
		node = node.Next
		pos++
	}

	now := node.Next
	next := now.Next
	for pos < n {
		now.Next = next.Next
		next.Next = node.Next
		node.Next = next

		next = now.Next
		pos++
	}
	return head.Next
}