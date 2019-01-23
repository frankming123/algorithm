// 7/9...
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    int *array1 = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array1[i];
    cin >> m;

    int mid = (m + n - 1) / 2;
    int l1 = 0, l2 = 0, input;
    cin >> input;
    while (l1 + l2 < mid) {
        // printf("l1:%d %d l2:%d %d\n", l1, array1[l1], l2, input);
        if (l1 >= n - 1) {
            cin >> input;
            l2++;
            continue;
        } else if (l2 >= m - 1) {
            l1++;
            continue;
        }
        if (array1[l1] < input)
            l1++;
        else {
            cin >> input;
            l2++;
        }
    }

    printf("%d", array1[l1] < input ? array1[l1] : input);

    return 0;
}
