/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]

Output: 1->1->2->3->4->4->5->6
*/

type ListNode struct {
    Val int
    Next *ListNode
}

func mergeKLists1(lists []*ListNode) *ListNode {
	intArray := make([]int, 0)
	head := &ListNode{}
	node := head
	for i := 0; i < len(lists); i++ {
		for lists[i] != nil {
			intArray = append(intArray, lists[i].Val)
			lists[i] = lists[i].Next
		}
	}

	InsertSort(intArray)

	for i := 0; i < len(intArray); i++ {
		node.Next = &ListNode{intArray[i], nil}
		node = node.Next
	}
	return head.Next
}

func mergeKLists2(lists []*ListNode) *ListNode {
	res:=mergeTwoLists(lists[0],lists[1])

	for i:=2;i<len(lists);i++{
		res=mergeTwoLists(res,lists[i])
	}
	return res
}

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

func InsertSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0 && nums[j] > nums[j+1]; j-- {
			nums[j], nums[j+1] = nums[j+1], nums[j]
		}
	}
}