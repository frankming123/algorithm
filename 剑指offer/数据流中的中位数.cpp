#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> v;
    void Insert(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }

    double GetMedian() {
        if (v.size() % 2 == 0)
            return (v[v.size() / 2 - 1] + v[v.size() / 2]) / double(2);
        else
            return v[v.size() / 2];
    }
};
int main() {
    return 0;
}