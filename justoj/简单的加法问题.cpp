#include <iostream>
#include <cstdio>

using namespace std;

unsigned long array[1000000];

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    unsigned long a, b;
    for (int i = 0; i < n; i++) {
        scanf("%lu%lu", &a, &b);
        if (a != (1UL << 63) && b != (1UL << 63))
            array[i] = a + b;
        else
            array[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (array[i] == -1)
            printf("18446744073709551616\n");
        else
            printf("%lu\n", array[i]);
    }

    return 0;
}
