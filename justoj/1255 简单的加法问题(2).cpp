#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int appears[100001] = {0};
    int n;
    cin >> n;
    int nums[n];
    int tmpnum;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] += 50000;
        appears[nums[i]]++;
    }
    if (n < 3) {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            tmpnum = nums[i] + nums[j] - 50000;
            if (tmpnum < 0 || tmpnum > 100000)
                continue;

            int tmp = 0;
            if (nums[i] == tmpnum)
                tmp++;
            if (nums[j] == tmpnum)
                tmp++;
            count += appears[tmpnum] - tmp;
        }
    cout << count << endl;
    return 0;
}
