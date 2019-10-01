#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
class Solution {
  public:
    bool isSame(TreeNode *root1, TreeNode *root2) {
        if (root2 == NULL)
            return true;
        if (root1 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if (isSame(pRoot1, pRoot2))
            return true;
        return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
int main() {
    Solution s;
    TreeNode *root1 = new TreeNode(8);
    root1->left = new TreeNode(8);
    root1->left->left = new TreeNode(9);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(7);
    root1->right = new TreeNode(7);
    TreeNode *root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(2);
    cout << s.HasSubtree(root1, root2);
    return 0;
}