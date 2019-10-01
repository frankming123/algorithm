#include <iostream>
#include <stack>

using namespace std;

#define lowbit(x) (x & -x)

int n;
int tree[100001];
stack<int> st;
int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += tree[i];
    return sum;
}
void update(int x, int val) {
    for (int i = x; i < 100001; i += lowbit(i))
        tree[i] += val;
}
int peekMedian() {
    int mid = (st.size() + 1) / 2;
    int l = 0, r = 100000;
    while (l < r) {
        int cnt = (l + r) / 2;
        if (getSum(cnt) < mid)
            l = cnt + 1;
        else
            r = cnt;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    char s[12];
    int tmp;
    while (n--) {
        scanf("%s", s);
        if (s[1] == 'o') {
            if (!st.empty()) {
                printf("%d\n", st.top());
                update(st.top(), -1);
                st.pop();
            } else
                printf("Invalid\n");
        } else if (s[1] == 'u') {
            scanf("%d", &tmp);
            st.push(tmp);
            update(st.top(), 1);
        } else {
            if (!st.empty())
                printf("%d\n", peekMedian());
            else
                printf("Invalid\n");
        }
    }
    return 0;
}