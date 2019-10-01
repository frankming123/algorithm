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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(7);
    s.Mirror(root);
    cout << root->val << " " << root->left->val << " " << root->right->val;
    return 0;
}