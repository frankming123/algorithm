#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num;

bool isSorted() {
    for (int i = 1; i < num.size(); i++)
        if (num[i - 1] > num[i])
            return false;
    return true;
}

int main() {
    scanf("%d", &n);
    num.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    int cnt = 0;
    while (!isSorted()) {
        int minn = num[0], pos = 0;
        for (int i = 0; i < num.size(); i++)
            if (num[i] < minn) {
                minn = num[i];
                pos = i;
            }
        num.erase(num.begin() + pos);
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}