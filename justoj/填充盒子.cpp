#include <algorithm>
#include <iostream>

using namespace std;

bool calc(int a, int b, int c) {
    int nums[3] = {a, b, c};
    sort(nums, nums + 3);
    if (nums[2] == 1)
        return false;
    if (nums[2] % 2 == 1)
        return calc(nums[0], nums[1], nums[2] - 1) && calc(nums[0], nums[1], 1);
    if (nums[0] % 1 == 0 && nums[1] % 1 == 0 && nums[2] % 2 == 0)
        return true;
    return false;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    bool res[t];
    int a, b, c;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        res[i] = calc(a, b, c);
    }
    for (int i = 0; i < t; i++)
        cout << (res[i] ? "Yes" : "No") << endl;
    return 0;
}