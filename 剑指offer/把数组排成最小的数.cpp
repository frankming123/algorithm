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
    static bool cmp(string &a, string &b) {
        return (a + b) < (b + a);
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> v;
        for (int i = 0; i < numbers.size(); i++)
            v.push_back(to_string(numbers[i]));
        sort(v.begin(), v.end(), cmp);
        string res;
        for (int i = 0; i < v.size(); i++) {
            // cout << v[i] << endl;
            res += v[i];
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v = {3, 32, 321};
    string res = s.PrintMinNumber(v);
    cout << res;
    return 0;
}