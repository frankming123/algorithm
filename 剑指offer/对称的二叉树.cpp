#include <bits/stdc++.h>
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
    bool run(TreeNode *l, TreeNode *r) {
        if (l == NULL && r == NULL)
            return true;
        if (l == NULL || r == NULL)
            return false;
        if (l->val != r->val)
            return false;
        return run(l->left, r->right) && run(l->right, r->left);
    }
    bool isSymmetrical(TreeNode *pRoot) {
        if (pRoot == NULL)
            return true;
        return run(pRoot->left, pRoot->right);
    }
};
int main() {
    Solution s;

    return 0;
}