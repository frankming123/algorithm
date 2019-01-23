#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string to13(int num) {
    if (num == 0)
        return "00";
    string res;
    while (num != 0) {
        int tmp = num % 13;
        res += tmp < 10 ? (tmp + '0') : (tmp - 10 + 'A');
        num /= 13;
    }
    reverse(res.begin(), res.end());
    if (res.length() == 1)
        res.insert(res.begin(), '0');
    return res;
}

int main(int argc, char const *argv[]) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << "#" << to13(a) << to13(b) << to13(c) << endl;

    return 0;
}
