#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> v;
        int now = 1;
        int len = 1;
        for (; now * 2 < sum; now++) {
            int total = 0;
            int i = 0;
            for (; total < sum; i++) {
                total += i + now;
            }
            if (total == sum) {
                len = i;
                break;
            }
        }
        // printf("now:%d len:%d\n", now, len);
        if (len == 1)
            return v;
        v.push_back(vector<int>(len));
        for (int i = 0; i < len; i++)
            v[v.size() - 1][i] = now + i;

        int t1 = 0, t2 = 0;
        while (len >= 3) {
            len--;
            t1 += now + len;
            if (t1 % len == 0) {
                t2 = t1 / len;
                // printf("now:%d len:%d\n", now + t2, len);
                v.push_back(vector<int>(len));
                for (int i = 0; i < len; i++)
                    v[v.size() - 1][i] = now + t2 + i;
            }
        }
        return v;
    }
};
int main() {
    Solution s;
    vector<vector<int>> v = s.FindContinuousSequence(100);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
    return 0;
}