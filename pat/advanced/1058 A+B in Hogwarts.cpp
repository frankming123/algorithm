#include <iostream>

using namespace std;

int main() {
    int a1, a2, b1, b2, c1, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);

    int a3, b3, c3;
    int add;
    c3 = (c1 + c2) % 29;
    add = (c1 + c2) / 29;
    b3 = (b1 + b2 + add) % 17;
    add = (b1 + b2 + add) / 17;
    a3 = a1 + a2 + add;
    printf("%d.%d.%d\n", a3, b3, c3);
    return 0;
}