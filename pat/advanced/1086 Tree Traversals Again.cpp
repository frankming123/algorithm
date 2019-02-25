#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> pre, in;
bool flag;

void dfs(int l1, int r1, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2)
        return;
    int root = pre[l1];
    int pos = l2;
    while (pos < r2 && in[pos] != root)
        pos++;

    dfs(l1 + 1, l1 + 1 + pos - l2, l2, pos);
    dfs(l1 + 1 + pos - l2, r1, pos + 1, r2);

    if (flag)
        printf(" ");
    printf("%d", root);
    flag = true;
}

int main() {
    cin >> n;
    string s;
    int tmp;
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        cin >> s;
        if (s[1] == 'u') {
            cin >> tmp;
            st.push(tmp);
            pre.push_back(tmp);
        } else {
            in.push_back(st.top());
            st.pop();
        }
    }
    dfs(0, n, 0, n);
    return 0;
}