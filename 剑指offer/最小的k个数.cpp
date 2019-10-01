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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size())
            return vector<int>();
        sort(input.begin(), input.end());
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> res = s.GetLeastNumbers_Solution(v, 4);
    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}