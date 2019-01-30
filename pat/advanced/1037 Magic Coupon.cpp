#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coupon(n);
    for (int i = 0; i < n; i++)
        cin >> coupon[i];
    int m;
    cin >> m;
    vector<int> product(m);
    for (int i = 0; i < m; i++)
        cin >> product[i];
    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());

    int i = 0;
    int total = 0;
    while (i < n && i < m && coupon[i] < 0 && product[i] < 0) {
        total += coupon[i] * product[i];
        i++;
    }
    i = 0;
    while (i < n && i < m && coupon[n - 1 - i] > 0 && product[m - 1 - i] > 0) {
        total += coupon[n - 1 - i] * product[m - 1 - i];
        i++;
    }
    printf("%d\n", total);
    return 0;
}