/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:

You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

func buildTree(inorder []int, postorder []int) *TreeNode {
	nlen := len(inorder)
	if nlen == 0 {
		return nil
	}
	root := &TreeNode{postorder[nlen-1], nil, nil}
	treemap := make(map[int]struct{})
	i, j := 0, 0
	for inorder[i] != root.Val {
		treemap[inorder[i]] = struct{}{}
		i++
	}
	for len(treemap) != 0 {
		delete(treemap, postorder[j])
		j++
	}
	root.Left = buildTree(inorder[:i], postorder[:j])
	root.Right = buildTree(inorder[i+1:], postorder[j:nlen-1])
	return root
}