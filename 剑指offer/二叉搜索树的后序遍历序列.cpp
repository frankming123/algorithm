#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return run(sequence, 0, sequence.size() - 1);
    }
    bool run(vector<int> &seq, int l, int r) {
        if (l >= r)
            return true;
        int pos = l;
        while (seq[pos] < seq[r])
            pos++;
        // printf("l:%d r:%d pos:%d\n", l, r, pos);
        for (int i = pos + 1; i < r; i++)
            if (seq[i] < seq[r])
                return false;

        return run(seq, l, pos - 1) && run(seq, pos, r - 1);
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 4, 2, 3};
    cout << s.VerifySquenceOfBST(v);
    return 0;
}