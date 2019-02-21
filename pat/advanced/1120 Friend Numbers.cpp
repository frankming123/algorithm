#include <iostream>
#include <vector>

using namespace std;

int cnt(int n) {
    int res = 0;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int cnts[10000];

int main() {
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cnts[cnt(num)] = 1;
    }

    int count = 0;
    for (int i = 0; i < 10000; i++) {
        if (cnts[i])
            count++;
    }
    cout << count << endl;
    bool flag = false;
    for (int i = 0; i < 10000; i++) {
        if (cnts[i]) {
            if (flag)
                cout << " ";
            flag = true;
            cout << i;
        }
    }
    return 0;
}