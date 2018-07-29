type ListNode struct {
    Val int
    Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	//store the num that l1's Val add l2's Val and then divide 10
	rem:=0
	//the returned ListNode's pre-head
	res:=&ListNode{}
	//used to increase the returned ListNode
	now:=res
	for l1!=nil||l2!=nil{
		//if l1 is not existed,treat it's Val as 0
		if l1==nil{
			l1=&ListNode{}
		}
		//the same as l1
		if l2==nil{
			l2=&ListNode{}
		}

		sum:=l1.Val+l2.Val+rem
		rem=sum/10
		now.Next=&ListNode{sum%10,nil}
		//for the loop
		now=now.Next
		l1=l1.Next
		l2=l2.Next
	}
	//the last:if rem is not 0,then add a node to store it
	if rem!=0{
		now.Next=&ListNode{rem,nil}
	}
	return res.Next
}