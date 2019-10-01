#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool Find(int target, vector<vector<int> > array) {
        int r = array.size() - 1, l = 0;
        while (r >= 0 && l <= array[0].size()) {
            if (target > array[r][l]) {
                l++;
            } else if (target < array[r][l]) {
                r--;
            } else
                return true;
        }
        return false;
    }
};
int main() {
    vector<vector<int> > v(4, vector<int>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            v[i][j]=j+i;
        }
    }
    Solution s;
    cout<<s.Find(6,v)<<endl;
    return 0;
}