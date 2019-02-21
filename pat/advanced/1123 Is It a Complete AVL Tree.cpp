#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int val;
    struct node *l, *r;
};

node *leftRotate(node *root) {
    node *tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    return tmp;
}
node *rightRotate(node *root) {
    node *tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    return tmp;
}
node *leftRightRotate(node *root) {
    root->l = leftRotate(root->l);
    return rightRotate(root);
}
node *rightLeftRotate(node *root) {
    root->r = rightRotate(root->r);
    return leftRotate(root);
}
int getHeight(node *root) {
    if (root == NULL)
        return 0;
    return max(getHeight(root->l), getHeight(root->r)) + 1;
}
node *insert(node *root, int val) {
    if (root == NULL) {
        root = new node();
        root->val = val;
        return root;
    } else if (val < root->val) {
        root->l = insert(root->l, val);
        int l = getHeight(root->l), r = getHeight(root->r);
        if (l - r >= 2) {
            if (val < root->l->val)
                root = rightRotate(root);
            else
                root = leftRightRotate(root);
        }
    } else {
        root->r = insert(root->r, val);
        int l = getHeight(root->l), r = getHeight(root->r);
        if (r - l >= 2) {
            if (val >= root->r->val)
                root = leftRotate(root);
            else
                root = rightLeftRotate(root);
        }
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    node *root = NULL;
    int t;
    while (n--) {
        cin >> t;
        root = insert(root, t);
    }
    queue<node *> qu;
    vector<int> res;
    qu.push(root);
    bool flag = false;
    bool isis = false;
    while (!qu.empty()) {
        node *now = qu.front();
        qu.pop();
        res.push_back(now->val);
        if (flag && (now->l != NULL || now->r != NULL))
            isis = true;
        if (now->l == NULL || now->r == NULL)
            flag = true;
        if (now->l != NULL)
            qu.push(now->l);
        if (now->r != NULL)
            qu.push(now->r);
    }
    for (int i = 0; i < res.size(); i++) {
        if (i != 0)
            printf(" ");
        printf("%d", res[i]);
    }
    printf("\n%s", isis ? "NO" : "YES");
    return 0;
}