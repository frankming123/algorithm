#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> diamonds(n);
    for (int i = 0; i < n; i++)
        cin >> diamonds[i];

    int total = 0, mintotal = 1 << 31 - 1;
    vector<int> res;

    int i = 0, j = 0;
    while (j < n) {
        //printf("total: %d diamonds[j]: %d\n", total, diamonds[j]);
        total += diamonds[j];
        while (total - diamonds[i] >= m) {
            total -= diamonds[i];
            i++;
        }
        j++;

        if (total >= m) {
            if (total < mintotal) {
                res.clear();
                res.push_back(i);
                res.push_back(j);
                mintotal = total;
            } else if (total == mintotal) {
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    for (int i = 0; i < res.size(); i += 2)
        printf("%d-%d\n", res[i] + 1, res[i + 1]);
    return 0;
}