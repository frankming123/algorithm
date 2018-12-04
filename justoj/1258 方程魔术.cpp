#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    cin >> a >> b;
    cout << ((a - (a ^ b) - b) == 0 ? "Yes" : "No") << endl;
    return 0;
}
