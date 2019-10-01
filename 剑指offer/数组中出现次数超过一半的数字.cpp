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
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> mmap;
        for (int i = 0; i < numbers.size(); i++)
            if (mmap.find(numbers[i]) == mmap.end())
                mmap[numbers[i]] = 1;
            else
                mmap[numbers[i]]++;
        int len = numbers.size() / 2;
        for (map<int, int>::iterator it = mmap.begin(); it != mmap.end(); it++)
            if (it->second > len)
                return it->first;
        return 0;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout<<s.MoreThanHalfNum_Solution(v);
    return 0;
}