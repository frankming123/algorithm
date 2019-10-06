#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        vector<int> res;
        if (size == 0 || size > num.size())
            return res;
        int l = 0, r = size;
        map<int, int, std::greater<int>> mmap;
        for (int i = l; i < r; i++) {
            if (mmap.find(num[i]) != mmap.end())
                mmap[num[i]]++;
            else
                mmap[num[i]] = 1;
        }
        res.push_back(mmap.begin()->first);
        while (r != num.size()) {
            if (mmap.find(num[r]) != mmap.end())
                mmap[num[r]]++;
            else
                mmap[num[r]] = 1;
            r++;

            mmap.erase(num[l]);
            l++;
            res.push_back(mmap.begin()->first);
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> res = s.maxInWindows(v, 0);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}