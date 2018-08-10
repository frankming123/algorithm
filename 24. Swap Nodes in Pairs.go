/*
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	res := &ListNode{}
	node := res

	for head != nil && head.Next != nil {
		node.Next = head.Next
		tmp := head.Next.Next
		node.Next.Next = head
		head = tmp
		node = node.Next.Next
	}

	if head != nil {
		node.Next = head
		node = node.Next
	}
	node.Next = nil
	return res.Next
}