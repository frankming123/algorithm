#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int *duplication) {
        vector<int> v(length, 0);
        for (int i = 0; i < length; i++)
            v[numbers[i]]++;
        for (int i = 0; i < length; i++) {
            if (v[numbers[i]] > 1) {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    int res;
    int num[]={2,3,1,0,2,5,3};
    s.duplicate(num,7,&res);
    cout<<res;
    return 0;
}