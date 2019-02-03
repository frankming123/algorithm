#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct stu {
    char name[5];
};

bool cmp(stu &a, stu &b) {
    return strcmp(a.name, b.name) < 0;
}

int main() {
    int n, k;
    scanf("%d%d\n", &n, &k);

    vector<vector<stu>> array(k);
    stu str;
    for (int i = 0; i < n; i++) {
        scanf("%s", str.name);
        int nums, course;
        cin >> nums;
        while (nums--) {
            scanf("%d", &course);
            course--;
            array[course].push_back(str);
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d %d\n", i + 1, array[i].size());
        sort(array[i].begin(), array[i].end(), cmp);
        for (int j = 0; j < array[i].size(); j++)
            printf("%s\n", array[i][j].name);
    }

    return 0;
}