#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        set<int> sset;
        for (int i = 0; i < data.size(); i++) {
            if (sset.find(data[i]) != sset.end())
                sset.erase(data[i]);
            else
                sset.insert(data[i]);
        }
        set<int>::iterator it = sset.begin();
        *num1 = *it;
        it++;
        *num2 = *it;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 1};
    int res1, res2;
    s.FindNumsAppearOnce(v, &res1, &res2);
    cout << res1 << res2;
    return 0;
}