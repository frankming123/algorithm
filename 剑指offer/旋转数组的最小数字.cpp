#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        int l = 0, r = rotateArray.size() - 1;
        int med;
        while (l < r) {
            med = (r + l) / 2;
            if (rotateArray[med] >= rotateArray[l] && rotateArray[med] >= rotateArray[r]) {
                l = med + 1;
            } else if (rotateArray[med] <= rotateArray[l] && rotateArray[med] <= rotateArray[r]) {
                r = med;
            } else {
                break;
            }
        }
        return rotateArray[l];
    }
};

int main() {
    Solution s;
    vector<int> v;
    int n;cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout << s.minNumberInRotateArray(v);
    return 0;
}