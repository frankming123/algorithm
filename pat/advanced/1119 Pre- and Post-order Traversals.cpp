#include <iostream>
#include <vector>

using namespace std;

int n;
int pre[30], post[30];
vector<int> in;

bool flag;
void build(int l1, int r1, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2)
        return;
    int root = pre[l1];
    if (l1 + 1 == r1) {
        in.push_back(root);
        return;
    }

    int pos = l2;
    int lchild = pre[l1 + 1];
    while (post[pos] != lchild)
        pos++;
    int rchild = post[r2 - 2];
    if (rchild == post[pos])
        flag = true;
    build(l1 + 1, l1 + 1 + pos - l2 + 1, l2, pos + 1);
    in.push_back(root);
    build(l1 + pos - l2 + 2, r1, pos + 1, r2 - 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> post[i];

    build(0, n, 0, n);
    printf("%s\n%d", flag ? "No" : "Yes", in[0]);
    for (int i = 1; i < in.size(); i++) {
        printf(" %d", in[i]);
    }
    printf("\n");
    return 0;
}