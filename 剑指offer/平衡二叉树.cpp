#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
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
    int TreeDepth(TreeNode *pRoot) {
        if (pRoot == NULL)
            return 0;
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
    bool IsBalanced_Solution(TreeNode *pRoot) {
        if (pRoot == NULL)
            return true;
        if (abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right)) > 1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    cout << s.IsBalanced_Solution(root);
    return 0;
}