#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<int>> stu;

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int tmp1, tmp2;
        string tmp3;
        cin >> tmp1 >> tmp2;
        while (tmp2--) {
            cin >> tmp3;
            stu[tmp3].push_back(tmp1);
        }
    }

    vector<string> lists(n);
    for (int i = 0; i < n; i++) {
        cin >> lists[i];
        sort(stu[lists[i]].begin(), stu[lists[i]].end());
    }

    for (int i = 0; i < n; i++) {
        cout << lists[i] << " " << stu[lists[i]].size();
        for (int j = 0; j < stu[lists[i]].size(); j++)
            cout << " " << stu[lists[i]][j];
        cout << endl;
    }
    return 0;
}