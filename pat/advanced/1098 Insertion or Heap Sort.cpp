// fuck the heap sort
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int num[100], mid[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
        cin >> mid[i];

    int pos = 1;
    while (pos < n && mid[pos - 1] < mid[pos])
        pos++;
    int pos2 = pos;
    while (pos2 < n && mid[pos2] == num[pos2])
        pos2++;
    if (pos2 == n) {
        printf("Insertion Sort\n");
        // while (pos > 0 && mid[pos] < mid[pos - 1]) {
        //     swap(mid[pos], mid[pos - 1]);
        //     pos--;
        // }
        sort(mid, mid + pos + 1);
    } else {
        printf("Heap Sort\n");
        pos = n - 1;
        while (pos >= 1 && mid[pos] > mid[0])
            pos--;
        swap(mid[0], mid[pos]);
        int now = 0, l = 1, r = 2;
        while (l < pos) {
            int big = l;
            if (r < pos && mid[r] > mid[big])
                big = r;
            // printf("now: %d big: %d\n", now, big);
            if (mid[now] > mid[big])
                break;
            swap(mid[now], mid[big]);
            now = big;
            l = big * 2 + 1;
            r = big * 2 + 2;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0)
            printf(" ");
        printf("%d", mid[i]);
    }

    return 0;
}