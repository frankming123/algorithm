#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int l = 0, r = array.size() - 1;
        while (l < r) {
            if (array[l] + array[r] < sum) {
                l++;
            } else if (array[l] + array[r] > sum) {
                r--;
            } else {
                return {array[l], array[r]};
            }
        }
        return {};
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> res = s.FindNumbersWithSum(v, 5);
    cout << res[0] << res[1];
    return 0;
}