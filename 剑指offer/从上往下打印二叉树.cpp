#include <cstdio>
#include <iostream>
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            // printf("now: %d\n", q.front()->val);
            TreeNode *now = q.front();
            res.push_back(now->val);
            q.pop();
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
        }
        return res;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<int> v = s.PrintFromTopToBottom(root);
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    return 0;
}