#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int jumpFloor(int number) {
        if (number <= 2)
            return number;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
int main() {
    Solution s;
    int n;cin>>n;
    cout << s.jumpFloor(n);
    return 0;
}