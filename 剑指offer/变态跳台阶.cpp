#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> num = vector<int>(10000, 0);

    int jumpFloorII(int number) {
        if (number == 1)
            return number;
        if (num[number] != 0)
            return num[number];
        int res = 0;
        for (int i = 1; i < number; i++)
            res += jumpFloorII(i);
        num[number] = res + 1;
        return num[number];
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.jumpFloorII(n);
    return 0;
}