#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    int res[t];
    for (int x = 0; x < t; x++) {
        int n;
        cin >> n;
        int array[10001] = {0};
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            array[tmp]++;
        }
        int count = 0;
        for (int i = 0; i < 10001; i++)
            if (array[i] > 1)
                count += array[i] - 1;
        res[x] = count;
    }

    for (int i = 0; i < t; i++)
        cout << res[i] << endl;
    return 0;
}
