#include <iostream>

using namespace std;

int n;
int cnt[1001];

int main() {
    scanf("%d", &n);
    int score;
    while (n--) {
        scanf("%d", &score);
        cnt[score]++;
    }
    bool flag = false;
    for (int i = 0; i <= 1000; i++) {
        while (cnt[i]--) {
            if (flag) {
                printf(" ");
            } else
                flag = true;
            printf("%d", i);
        }
    }
    return 0;
}