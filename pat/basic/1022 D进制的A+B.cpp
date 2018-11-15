/*
1022 D进制的A+B （20 分）
输入两个非负 10 进制整数 A 和 B (≤2​30−1)，输出 A+B 的 D
(1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103
*/
#include <iostream>
#include <vector>

using namespace std;

void itos(long n, int d, vector<int> &array) {
    while (n != 0) {
        array.push_back(n % d);
        n /= d;
    }
}

int main(int argc, char const *argv[]) {
    long a, b;
    int d;
    cin >> a >> b >> d;
    vector<int> array;
    itos(a + b, d, array);
    if (array.size() == 0)
        cout << 0;
    for (int i = array.size() - 1; i >= 0; i--)
        cout << array[i];
    return 0;
}
