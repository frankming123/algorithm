#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int array[100000] = {0};
    int left[100000] = {0};
    int right[100000] = {0};

    int count = 0;
    int res[100000] = {0};
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    left[0] = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > left[i - 1])
            left[i] = array[i];
        else
            left[i] = left[i - 1];
    }
    right[n - 1] = array[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (array[i] < right[i + 1])
            right[i] = array[i];
        else
            right[i] = right[i + 1];
    }

    for (int i = 0; i < n; i++) {
        if (array[i] == left[i] && array[i] == right[i]) {
            res[count++] = array[i];
        }
    }

    cout << count << endl;
    if (count > 0) {
        cout << res[0];
    }
    for (int i = 1; i < count; i++) {
        cout << " " << res[i];
    }
    cout << endl;
    return 0;
}
