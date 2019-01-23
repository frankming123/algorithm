#include <iostream>

using namespace std;

char v[100000];
int ne[100000];

bool passed[100000];

int main(int argc, char const *argv[]) {
    int addr1, addr2, n;
    cin >> addr1 >> addr2 >> n;

    int tmp;
    while (n--) {
        cin >> tmp;
        cin >> v[tmp];
        cin >> ne[tmp];
    }

    int now = addr1;
    while (now != -1) {
        passed[now] = true;
        now = ne[now];
    }
    now = addr2;
    while (now != -1 && !passed[now])
        now = ne[now];

    if (now == -1)
        printf("-1\n");
    else
        printf("%05d\n", now);
    return 0;
}
