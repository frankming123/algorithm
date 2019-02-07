#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int m, n, k;

bool run(vector<int> &nums) {
    stack<int> st;
    int add = 1;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (add <= num) {
            while (add <= num) {
                st.push(add);
                add++;
            }
            if (st.size() > m)
                return false;
            st.pop();
        } else {
            if (st.top() != num)
                return false;
            st.pop();
        }
    }
    return true;
}

int main() {
    cin >> m >> n >> k;
    vector<int> nums(n);
    while (k--) {
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        printf("%s\n", run(nums) ? "YES" : "NO");
    }
    return 0;
}