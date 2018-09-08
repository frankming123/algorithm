package usefulfuncs

type ListNode struct {
	Val  int
	Next *ListNode
}

func Travel(node *ListNode){
	for node!=nil{
		println(node.Val)
		node=node.Next
	}
}

func listNew(a ...int) *ListNode {
	list := &ListNode{0, nil}
	for i := range a {
		list.Next = &ListNode{i, nil}
		list = list.Next
	}
	return list
}

func Max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func Min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func Abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func PopSort(nums []int) {
	for i := 0; i < len(nums)-1; i++ {
		for j := 0; j < len(nums)-i-1; j++ {
			if nums[j] > nums[j+1] {
				nums[j], nums[j+1] = nums[j+1], nums[j]
			}
		}
	}
}

func InsertSort(nums []int) {
	for i := 1; i < len(nums); i++ {
		for j := i - 1; j >= 0 && nums[j] > nums[j+1]; j-- {
			nums[j], nums[j+1] = nums[j+1], nums[j]
		}
	}
}

func binarySearch(nums []int, target int) int {
	nLen := len(nums)
	if nLen == 0 {
		return -1
	}
	middle := nLen / 2

	if target == nums[middle] {
		return middle
	} else if target > nums[middle] {
		res := binarySearch(nums[middle+1:], target)
		if res == -1 {
			return -1
		}
		return res + middle + 1
	} else {
		return binarySearch(nums[:middle], target)
	}
}
