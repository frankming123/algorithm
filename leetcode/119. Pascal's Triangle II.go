/*
119. Pascal's Triangle II

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

func getRow(rowIndex int) []int {
	res:=[]int{1}
	for i:=0;i<rowIndex;i++{
		res=getNextRow(res)
	}
	return res
}

func getNextRow(row []int) []int {
	res := make([]int, len(row)+1)
	res[0] = row[0]
	for i := 0; i < len(row)-1; i++ {
		res[i+1] = row[i] + row[i+1]
	}
	res[len(res)-1] = row[len(row)-1]
	return res
}