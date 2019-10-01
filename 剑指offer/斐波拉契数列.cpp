#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int Fibonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};

int main() {
    Solution s;
    cout<<s.Fibonacci(5);
    return 0;
}