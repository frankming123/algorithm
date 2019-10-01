#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int t1, t2;
        if (stack2.empty()) {
            while (!stack1.empty()) {
                t1 = stack1.top();
                stack1.pop();
                stack2.push(t1);
            }
        }
        t1 = stack2.top();
        stack2.pop();
        return t1;
    }

  private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}