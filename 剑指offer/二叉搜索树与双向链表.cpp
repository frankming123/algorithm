#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
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
    TreeNode *pre = NULL, *res = NULL;
    void run(TreeNode *root) {
        if (root == NULL)
            return;
        run(root->left);

        // printf("now:%d\n", root->val);
        if (pre != NULL) {
            root->left = pre;
            pre->right = root;
            pre = root;
        } else {
            pre = root;
            res = root;
            // printf("res:%d\n", res->val);
        }

        run(root->right);
    }
    TreeNode *Convert(TreeNode *pRootOfTree) {
        run(pRootOfTree);
        return res;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    s.Convert(root);
    TreeNode *res = s.res;
    while (res) {
        printf("%d ", res->val);
        res = res->right;
    }
    return 0;
}