#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cnt[128];
    vector<char> v;
    Solution() {
        fill(cnt, cnt + 128, 0);
    }
    //Insert one char from stringstream
    void Insert(char ch) {
        v.push_back(ch);
        cnt[ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (int i = 0; i < v.size(); i++)
            if (cnt[v[i]] == 1)
                return v[i];
        return '#';
    }
};
int main() {
    Solution s;
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('g');
    s.Insert('o');
    s.Insert('o');
    s.Insert('g');
    s.Insert('l');
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;
    return 0;
}