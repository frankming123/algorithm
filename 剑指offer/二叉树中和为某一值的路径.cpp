#include <algorithm>
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
    bool cmp(vector<int> &a, vector<int> &b) {
        return a.size() > b.size();
    }
    vector<vector<int>> vv;
    vector<int> v;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        if (root == NULL)
            return vv;
        run(root, expectNumber);
        sort(vv.begin(), vv.end());
        return vv;
    }
    void run(TreeNode *root, int sum) {
        if (sum < 0)
            return;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            v.push_back(root->val);
            vv.push_back(v);
            v.pop_back();
            return;
        }

        v.push_back(root->val);
        if (root->left)
            run(root->left, sum - root->val);
        if (root->right)
            run(root->right, sum - root->val);
        v.pop_back();
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(3);
    vector<vector<int>> v = s.FindPath(root, 4);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }

    return 0;
}