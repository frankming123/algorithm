/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//Backtracking approach
func generateParenthesis(n int) []string {
	res:=make([]string,0)
	backTrack(&res,"",0,0,n)
	return res
}

func backTrack(res *[]string,s string,left,right,n int){
	if len(s)==n*2{
		*res=append(*res,s)
		return
	}

	if left<n{
		backTrack(res,s+"(",left+1,right,n)
	}
	if right<left{
		backTrack(res,s+")",left,right+1,n)
	}
}