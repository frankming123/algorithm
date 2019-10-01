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
    vector<int> path;
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty())
            return res;
        path = vector<int>(str.length(), 0);
        run(res, str, "", str.length());
        sort(res.begin(), res.end());
        vector<string> rres;
        rres.push_back(res[0]);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] == res[i - 1])
                continue;
            rres.push_back(res[i]);
        }
        return rres;
    }
    void run(vector<string> &res, string &str, string now, int rest) {
        if (rest == 0) {
            res.push_back(now);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            if (!path[i]) {
                path[i] = 1;
                run(res, str, now + str[i], rest - 1);
                path[i] = 0;
            }
        }
    }
};
int main() {
    Solution s;
    vector<string> v = s.Permutation("aaa");
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
    return 0;
}