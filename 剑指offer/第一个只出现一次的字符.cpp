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
    int cnt[128], pos[128];
    int FirstNotRepeatingChar(string str) {
        fill(cnt, cnt + 128, 0);
        fill(pos, pos + 128, 0);
        for (int i = 0; i < str.length(); i++) {
            if (pos[str[i]] == 0)
                pos[str[i]] = i;
            cnt[str[i]]++;
        }
        int res = 10010;
        for (int i = 0; i < 128; i++)
            if (cnt[i] == 1)
                res = min(res, pos[i]);
        return res == 10010 ? -1 : res;
    }
};
int main() {
    Solution s;
    cout << s.FirstNotRepeatingChar("abcdacd");
    return 0;
}