#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())
            return 0;
        int res = 0, maxn = 0, maxnn = array[0];
        for (int i = 0; i < array.size(); i++) {
            res += array[i];
            maxn = max(maxn, res);
            maxnn = max(maxnn, array[i]);
            if (res < 0)
                res = 0;
        }
        return maxnn < 0 ? maxnn : maxn;
    }
};
int main() {
    Solution s;
    vector<int> v = {-3, -2, -15};
    cout << s.FindGreatestSumOfSubArray(v);
    return 0;
}