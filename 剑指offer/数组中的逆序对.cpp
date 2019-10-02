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
    int cnt;
    int InversePairs(vector<int> data) {
        cnt = 0;
        mergeSort(data, 0, data.size());
        return cnt;
    }
    void mergeSort(vector<int> &data, int l, int r) {
        // printf("l:%d r:%d\n", l, r);
        if (l + 1 >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(data, l, mid);
        mergeSort(data, mid, r);
        merge(data, l, mid, r);
    }

    void merge(vector<int> &data, int l, int mid, int r) {
        vector<int> v(r - l);
        int index = 0;
        int p1 = l, p2 = mid;
        // printf("index:%d l:%d mid:%d r:%d\n", index, l, mid, r);
        while (index != v.size()) {
            if (p1 == mid) {
                v[index++] = data[p2++];
            } else if (p2 == r) {
                v[index++] = data[p1++];
            } else if (data[p1] > data[p2]) {
                // printf("p1:%d p2:%d %d %d\n", p1, p2, data[p1], data[p2]);
                cnt += mid - p1;
                cnt %= 1000000007;
                v[index++] = data[p2++];
            } else
                v[index++] = data[p1++];
        }
        for (int i = l; i < r; i++)
            data[i] = v[i - l];
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 0};
    cout << s.InversePairs(v);
    return 0;
}