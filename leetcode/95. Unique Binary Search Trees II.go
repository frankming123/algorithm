/*
95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3

Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]

Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTrees(n int) []*TreeNode {
	if n==0{
		return []*TreeNode{}
	}
	return helper(1, n)
}

func helper(start, end int) []*TreeNode {
	list := []*TreeNode{}
	if start > end {
		list = append(list, nil)
		return list
	}
	if start == end {
		list = append(list, &TreeNode{start, nil, nil})
		return list
	}

	left, right := []*TreeNode{}, []*TreeNode{}
	for i := start; i <= end; i++ {
		left = helper(start, i-1)
		right = helper(i+1, end)
		for _, lnode := range left {
			for _, rnode := range right {
				root := &TreeNode{i, nil, nil}
				root.Left = lnode
				root.Right = rnode
				list = append(list, root)
			}
		}
	}
	return list
}