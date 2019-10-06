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
    void run(TreeNode *root, int &cnt, TreeNode **res) {
        if (root == NULL || cnt == 0)
            return;

        run(root->left, cnt, res);
        if (cnt == 1)
            *res = root;
        cnt--;
        run(root->right, cnt, res);
    }
    TreeNode *KthNode(TreeNode *pRoot, int k) {
        TreeNode *res = NULL;
        run(pRoot, k, &res);
        return res;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout << s.KthNode(root, 2)->val;
    return 0;
}