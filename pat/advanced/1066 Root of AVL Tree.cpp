#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int val;
    node *l, *r;
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
        root->l = root->r = NULL;
        return root;
    } else if (val < root->val) {
        root->l = insert(root->l, val);
        int h1 = getHeight(root->l), h2 = getHeight(root->r);
        if (h1 - h2 >= 2) {
            if (val < root->l->val)
                root = rightRotate(root);
            else
                root = leftRightRotate(root);
        }
    } else {
        root->r = insert(root->r, val);
        int h1 = getHeight(root->l), h2 = getHeight(root->r);
        if (h2 - h1 >= 2) {
            if (val > root->r->val)
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
    int tmp;
    while (n--) {
        cin >> tmp;
        root = insert(root, tmp);
    }
    cout << root->val << endl;
    return 0;
}