// the amount also needs double???
#include <algorithm>
#include <iostream>

using namespace std;

struct product {
    double amount;
    double price;
    double earn;
};

bool cmp(product &a, product &b) {
    return a.earn > b.earn;
}

int main() {
    int n, d;
    cin >> n >> d;
    product pros[n];
    for (int i = 0; i < n; i++)
        cin >> pros[i].amount;
    for (int i = 0; i < n; i++) {
        cin >> pros[i].price;
        pros[i].earn = pros[i].price / pros[i].amount;
    }
    sort(pros, pros + n, cmp);
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (d >= pros[i].amount) {
            total += pros[i].price;
            d -= pros[i].amount;
        } else {
            total += d * pros[i].earn;
            break;
        }
    }
    // printf("%.2f\n", int((total + 0.005) * 100) / 100.0);
    printf("%.2f\n", total);
    return 0;
}