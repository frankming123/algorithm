#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *build(vector<int> &pre, vector<int> &in, int l1, int l2, int len) {
        if (len == 0)
            return NULL;
        TreeNode *node = new TreeNode(pre[l1]);
        int tmp = 0;
        while (in[l2 + tmp] != pre[l1])
            tmp++;
        node->left = build(pre, in, l1 + 1, l2, tmp);
        node->right = build(pre, in, l1 + 1 + tmp, l2 + 1 + tmp, len - tmp - 1);
        return node;
    }
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        TreeNode *root = build(pre, vin, 0, 0, pre.size());
        return root;
    }
};

int main() {
    Solution s;
    vector<int> pre={1, 2, 4, 7, 3, 5, 6, 8}, in={4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode *root = s.reConstructBinaryTree(pre, in);
    cout << root->val;

    return 0;
}