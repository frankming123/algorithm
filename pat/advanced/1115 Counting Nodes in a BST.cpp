#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val = 0;
    node *l = NULL, *r = NULL;
};

node *insert(node *tree, int val) {
    if (tree == NULL) {
        tree = new node();
        tree->val = val;
        return tree;
    } else if (val <= tree->val) {
        tree->l = insert(tree->l, val);
    } else {
        tree->r = insert(tree->r, val);
    }
    return tree;
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

    queue<node *> qu;
    qu.push(root);
    int prelen = 0, nowlen = 0;
    while (!qu.empty()) {
        int len = qu.size();
        prelen = nowlen;
        nowlen = len;
        while (len--) {
            node *now = qu.front();
            qu.pop();
            // printf("%d ", now->val);
            if (now->l != NULL)
                qu.push(now->l);
            if (now->r != NULL)
                qu.push(now->r);
        }
        // printf("\n");
    }
    printf("%d + %d = %d", nowlen, prelen, prelen + nowlen);
    return 0;
}