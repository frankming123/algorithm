#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long int

int n;
struct node {
    ll a, b;
};
vector<node> v;
bool cmp(node &a, node &b) {
    return a.b * b.a > b.b * a.a;
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &v[i].a, &v[i].b);
        sum += v[i].b;
    }
    sort(v.begin(), v.end(), cmp);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        sum -= v[i].b;
        res += sum * v[i].a;
    }
    printf("%lld\n", res);
    return 0;
}