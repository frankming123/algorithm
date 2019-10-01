#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> s;
        int now = 0;
        for (int i = 0; i < pushV.size(); i++) {
            s.push(pushV[i]);
            while (!s.empty() && s.top() == popV[now]) {
                s.pop();
                now++;
            }
        }
        return s.empty() ? true : false;
    }
};
int main() {
    Solution s;
    vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {4, 3, 5, 1, 2};
    cout << s.IsPopOrder(v1, v2);
    return 0;
}