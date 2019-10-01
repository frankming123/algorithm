#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void reOrderArray(vector<int> &array) {
        vector<int> even;
        int now = 0;
        for (int i = 0; i < array.size(); i++) {
            if (array[i] % 2) {
                array[now] = array[i];
                now++;
            } else {
                even.push_back(array[i]);
            }
        }
        for (int i = even.size() - 1; i >= 0; i--) {
            array[array.size() - even.size() + i] = even[i];
        }
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    s.reOrderArray(v);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}