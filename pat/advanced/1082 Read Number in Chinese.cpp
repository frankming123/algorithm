#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string suffix[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
vector<string> res;

void qian(int n) {
    int n1, n2, n3, n4, num = n;
    n1 = n % 10;
    n /= 10;
    n2 = n % 10;
    n /= 10;
    n3 = n % 10;
    n /= 10;
    n4 = n % 10;
    n /= 10;
    if (n4 != 0) {
        res.push_back(digit[n4]);
        res.push_back(suffix[2]);
        if (n3 == 0 && (n2 != 0 || n1 != 0))
            res.push_back(digit[0]);
    }
    if (n3 != 0) {
        res.push_back(digit[n3]);
        res.push_back(suffix[1]);
        if (n2 == 0 && n1 != 0)
            res.push_back(digit[0]);
    }
    if (n2 != 0) {
        res.push_back(digit[n2]);
        res.push_back(suffix[0]);
    }
    if (n1 != 0) {
        res.push_back(digit[n1]);
    }
}

int main() {
    int n, num1, num2, num3;
    cin >> n;
    if (n < 0) {
        n *= -1;
        res.push_back("Fu");
    } else if (n == 0) {
        cout << "ling";
        return 0;
    }
    num1 = n % 10000;
    n /= 10000;
    num2 = n % 10000;
    n /= 10000;
    num3 = n % 10000;
    n /= 10000;

    if (num3 != 0) {
        qian(num3);
        res.push_back(suffix[4]);
        if (num2 < 1000)
            res.push_back(digit[0]);
    }
    if (num2 != 0) {
        qian(num2);
        res.push_back(suffix[3]);
        if (num1 < 1000)
            res.push_back(digit[0]);
    }
    if (num1 != 0) {
        qian(num1);
    }

    for (int i = 0; i < res.size(); i++) {
        if (i != 0)
            cout << " ";
        cout << res[i];
    }
    return 0;
}