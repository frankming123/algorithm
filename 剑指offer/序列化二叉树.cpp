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
    string run1(TreeNode *root) {
        if (root == NULL)
            return "#";
        return to_string(root->val) + "!" + run1(root->left) + "!" + run1(root->right);
    }
    char *Serialize(TreeNode *root) {
        string s = run1(root);
        char *res = new char[s.length() + 1];
        strcpy(res, s.c_str());
        return res;
    }
    TreeNode *Deserialize(char *str) {
        stringstream ss(str);
        return run2(ss);
    }

    TreeNode *run2(stringstream &ss) {
        string s;
        getline(ss, s, '!');
        if (s == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(s));
        root->left = run2(ss);
        root->right = run2(ss);
        return root;
    }
};
int main() {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout << s.Serialize(root);
    return 0;
}