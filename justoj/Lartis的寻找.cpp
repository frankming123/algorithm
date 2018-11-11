#include <iostream>

using namespace std;

int calc(int n) {
    
    int num, xornum = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;
        xornum ^= num;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> num;
        xornum^=num;
    }
    return xornum;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int res[n];
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        res[i] = calc(num);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << endl;
    return 0;
}
