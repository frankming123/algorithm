'''
117. Populating Next Right Pointers in Each Node II

Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.

Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
'''

class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None


# just like the previous problem, parhaps the problem before can have a better solution
class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root == None:
            return None
        stack = [root]
        while len(stack) != 0:
            slen = len(stack)
            for i in range(slen):
                if i < slen-1:
                    stack[i].next = stack[i+1]
                if stack[i].left != None:
                    stack.append(stack[i].left)
                if stack[i].right != None:
                    stack.append(stack[i].right)
            stack = stack[slen:]