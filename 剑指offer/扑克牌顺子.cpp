#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() < 5)
            return false;
        sort(numbers.begin(), numbers.end());
        int l = 0;
        while (numbers[l] == 0)
            l++;
        for (int i = l; i < 5; i++) {
            if (i > 0 && numbers[i] == numbers[i - 1])
                return false;
        }
        if (numbers[4] - numbers[l] >= 5)
            return false;
        return true;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 3, 5, 0, 0};
    cout << s.IsContinuous(v);
    return 0;
}