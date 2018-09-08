/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	head = &ListNode{0, head}
	node := head
	greathead := &ListNode{0, nil}
	great := greathead
	for node.Next != nil {
		if node.Next.Val >= x {
			great.Next = node.Next
			great = great.Next
			node.Next = node.Next.Next
		} else {
			node = node.Next
		}
	}
	great.Next = nil
	node.Next = greathead.Next
	return head.Next
}