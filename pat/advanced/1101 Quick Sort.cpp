#include <iostream>
#include <vector>

using namespace std;

int n;
int num[100000];
int big[100000], small[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    small[0] = num[0];
    for (int i = 1; i < n; i++) {
        if (small[i - 1] < num[i])
            small[i] = num[i];
        else
            small[i] = small[i - 1];
    }
    big[n - 1] = num[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (big[i + 1] > num[i])
            big[i] = num[i];
        else
            big[i] = big[i + 1];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (num[i] >= small[i] && num[i] <= big[i])
            v.push_back(num[i]);
    }
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++) {
        if (i != 0)
            printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}