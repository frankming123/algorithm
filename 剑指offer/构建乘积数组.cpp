#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> multiply(const vector<int> &A) {
        vector<int> res(A.size());
        int cnt = 1;
        for (int i = 0; i < res.size(); i++) {
            res[i] = cnt;
            cnt *= A[i];
        }
        cnt = 1;
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] *= cnt;
            cnt *= A[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> num = {1, 2, 3, 4, 5};

    vector<int> res = s.multiply(num);
    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);
    return 0;
}