#include <algorithm>
#include <iostream>

using namespace std;

int n;
int ride[100000];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ride[i];

    sort(ride, ride + n, cmp);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (ride[i] <= cnt)
            break;
        cnt++;
    }
    cnt--;
    cout << cnt << endl;
    return 0;
}