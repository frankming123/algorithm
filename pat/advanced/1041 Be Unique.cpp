#include <iostream>

using namespace std;

short nums[100000];
short pos[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        nums[pos[i]]++;
    }

    for (int i = 0; i < n; i++)
        if (nums[pos[i]] == 1) {
            cout << pos[i] << endl;
            return 0;
        }
    cout << "None" << endl;
    return 0;
}