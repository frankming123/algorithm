#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int GetNumberOfK(vector<int> data, int k) {
        int cnt = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == k)
                cnt++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 0};
    cout << s.InversePairs(v);
    return 0;
}