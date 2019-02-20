#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string z;
    cin >> n;
    while (n--) {
        cin >> z;
        string a = z.substr(0, z.length() / 2), b = z.substr(z.length() / 2);
        int num1 = stoi(z), num2 = stoi(a), num3 = stoi(b);
        if (num2 == 0 || num3 == 0)
            cout << "No" << endl;
        else if (num1 % (num2 * num3) == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
