#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int n;
double p, r;
int retailer[100000];
set<int> matrix[100000];
double total;

void run(int now, int level) {
    if (retailer[now] != 0) {
        total += retailer[now] * p * pow(r, level);
        return;
    }

    for (set<int>::iterator it = matrix[now].begin(); it != matrix[now].end(); it++)
        run(*it, level + 1);
}

int main() {
    cin >> n >> p >> r;
    r = (100.0 + r) / 100.0;
    int tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        if (tmp1 == 0) {
            cin >> tmp2;
            retailer[i] = tmp2;
        } else {
            while (tmp1--) {
                cin >> tmp2;
                matrix[i].insert(tmp2);
            }
        }
    }
    run(0, 0);
    printf("%.1lf", total);
    return 0;
}