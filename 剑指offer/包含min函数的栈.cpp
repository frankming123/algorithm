#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    stack<int> s1, s2;
    void push(int value) {
        if (s2.empty() || s2.top() >= value)
            s2.push(value);
        s1.push(value);
    }
    void pop() {
        if (s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.min();
    s.pop();
    return 0;
}