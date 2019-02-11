#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> stack(100001);
vector<int> sorts(100001, 0);
int top = -1;

int lowbit(int i) {
    return i & (-i);
}
int getSum(int n) {
    int sum = 0;
    for (int i = n; i > 0; i -= lowbit(i))
        sum += sorts[i];
    return sum;
}
int update(int n, int m) {
    for (int i = n; i < 100001; i += lowbit(i))
        sorts[i] += m;
}

void push(int n) {
    top++;
    stack[top] = n;
    update(n, 1);
}
int pop() {
    if (top == -1)
        return -1;
    update(stack[top], -1);
    return stack[top--];
}
int peekmedian() {
    if (top == -1)
        return -1;

    int l = 0, r = 100000, middem = top / 2 + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        //printf("l: %d r: %d mid: %d\n", l, r, mid);
        if (middem > getSum(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    int n;
    scanf("%d\n", &n);
    char str[16];
    int num;
    while (n--) {
        scanf("%s", str);
        if (str[1] == 'o') {
            num = pop();
            if (num == -1)
                cout << "Invalid" << endl;
            else
                cout << num << endl;
        } else if (str[1] == 'e') {
            num = peekmedian();
            if (num == -1)
                cout << "Invalid" << endl;
            else
                cout << num << endl;
        } else {
            scanf("%d", &num);
            push(num);
        }
    }
    return 0;
}