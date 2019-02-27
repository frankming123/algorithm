#include <iostream>

using namespace std;

int n;
double array1[1001];
double array2[1001];
double res[2001];

int main(int argc, char const *argv[]) {
    cin >> n;
    int tmp;
    while (n--) {
        double a;
        cin >> tmp >> a;
        array1[tmp] = a;
    }
    cin >> n;
    while (n--) {
        double a;
        cin >> tmp >> a;
        array2[tmp] = a;
    }

    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            res[i + j] += array1[i] * array2[j];

    int count = 0;
    for (int i = 0; i < 2001; i++)
        if (res[i] != 0)
            count++;

    printf("%d", count);

    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0)
            printf(" %d %.1lf", i, res[i]);

    return 0;
}
