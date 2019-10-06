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
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty()) {
            int len = q.size();
            vector<int> v(len);
            for (int i = 0; i < len; i++) {
                TreeNode *val = q.front();
                v[i] = val->val;
                if (val->left != NULL)
                    q.push(val->left);
                if (val->right != NULL)
                    q.push(val->right);
                q.pop();
            }
            res.push_back(v);
        }
        return res;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    vector<vector<int>> v = s.Print(root);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    return 0;
}