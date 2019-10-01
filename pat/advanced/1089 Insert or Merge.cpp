#include <algorithm>
#include <iostream>

using namespace std;

int n;
int pre[100], now[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> now[i];

    int l = 0;
    while (l < n - 1 && now[l] < now[l + 1])
        l++;
    int r = n - 1;
    while (r >= 0 && now[r] == pre[r])
        r--;
    if (l == r) {
        printf("Insertion Sort\n");
        sort(now, now + l + 2);
    } else {
        printf("Merge Sort\n");
        int k = 1, flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < n; i++)
                if (pre[i] != now[i])
                    flag = 1;
            k *= 2;
            for (int i = 0; i < n / k; i++)
                sort(pre + i * k, pre + (i + 1) * k);
            sort(pre + n / k * k, pre + n);
        }
        for (int i = 0; i < n; i++)
            now[i] = pre[i];
    }

    for (int i = 0; i < n; i++) {
        if (i != 0)
            printf(" ");
        printf("%d", now[i]);
    }
    return 0;
}