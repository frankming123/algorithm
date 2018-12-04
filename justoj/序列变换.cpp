#include <iostream>
#include <vector>

using namespace std;

#define LEN 100000

int n;
vector<int> array(LEN);
vector<int> arrcpy(LEN);

bool calc(int num) {
    arrcpy[0] = array[0] - num;
    for (int i = 1; i < n; i++) {
        if (array[i] + num <= arrcpy[i - 1])
            return false;
        arrcpy[i] =
            array[i] - num > arrcpy[i - 1] ? array[i] - num : arrcpy[i - 1] + 1;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int a = 1; a <= t; a++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> array[i];
        int left = 0, right = 1000000000;
        while (left < right) {
            int mid = (left + right) / 2;
            if (calc(mid))
                right = mid;
            else
                left = mid + 1;
        }
        cout << "Case #" << a << ":\n" << left << endl;
    }
    return 0;
}
