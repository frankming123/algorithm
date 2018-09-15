/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:

You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	rootnum := preorder[0]
	root := &TreeNode{rootnum, nil, nil}
	treemap := make(map[int]struct{})
	inpos := 0
	prepos := 1
	for ; inorder[inpos] != rootnum; inpos++ {
		treemap[inorder[inpos]] = struct{}{}
	}
	for ; len(treemap) != 0; prepos++ {
		delete(treemap, preorder[prepos])
	}

	root.Left = buildTree(preorder[1:prepos], inorder[:inpos])
	root.Right = buildTree(preorder[prepos:], inorder[inpos+1:])
	return root
}