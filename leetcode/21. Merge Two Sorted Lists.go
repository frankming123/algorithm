/*
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	node := head
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			node.Next = l1
			node = node.Next
			l1 = l1.Next
		} else {
			node.Next = l2
			node = node.Next
			l2 = l2.Next
		}
	}
	if l1 != nil {
		node.Next = l1
	}
	if l2 != nil {
		node.Next = l2
	}
	return head.Next
}