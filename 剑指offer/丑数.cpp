#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int GetUglyNumber_Solution(int index) {
        if (index < 1)
            return 0;
        int a = 0, b = 0, c = 0;
        vector<int> res(index, 1);
        for (int i = 1; i < index; i++) {
            res[i] = min(res[a] * 2, min(res[b] * 3, res[c] * 5));
            if (res[i] == res[a] * 2)
                a++;
            if (res[i] == res[b] * 3)
                b++;
            if (res[i] == res[c] * 5)
                c++;
        }
        return res[index - 1];
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.GetUglyNumber_Solution(n);
    return 0;
}