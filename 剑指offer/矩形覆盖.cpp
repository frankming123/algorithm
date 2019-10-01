#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> v = vector<int>(1000, 0);
    int rectCover(int number) {
        if (number <= 3)
            return number;
        if (v[number] != 0)
            return v[number];
        v[number] = rectCover(number - 1) + rectCover(number - 2);
        return v[number];
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.rectCover(n);
    return 0;
}