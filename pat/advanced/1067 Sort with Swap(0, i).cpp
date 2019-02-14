#include <algorithm>
#include <iostream>

using namespace std;

int nums[100000];
int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[num] = i;
    }

    int count = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] != i) {
            while (nums[0] != 0) {
                swap(nums[0], nums[nums[0]]);
                count++;
            }
            if (nums[i] != i) {
                swap(nums[0], nums[i]);
                count++;
            }
        }
    }

    cout << count << endl;
    // for (int i = 0; i < n; i++)
    //     cout << nums[i] << " ";
    // cout << endl;
    return 0;
}