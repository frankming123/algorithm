#include <algorithm>
#include <iostream>

using namespace std;

int rope[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rope[i];

    sort(rope, rope + n);
    int res = rope[0];
    for (int i = 1; i < n; i++) {
        res += rope[i];
        res /= 2;
    }
    cout << res << endl;
    return 0;
}