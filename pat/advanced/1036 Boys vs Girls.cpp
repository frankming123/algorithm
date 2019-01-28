#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> name(n), gender(n), ID(n);
    vector<int> grade(n);
    for (int i = 0; i < n; i++)
        cin >> name[i] >> gender[i] >> ID[i] >> grade[i];

    int score = -1;
    for (int i = 0; i < n; i++)
        if (gender[i] == "F" && grade[i] > score)
            score = grade[i];

    bool flag = false;
    int g1 = score, g2;
    if (score == -1) {
        printf("Absent\n");
        flag = true;
    } else
        for (int i = 0; i < n; i++)
            if (grade[i] == score) {
                cout << name[i] << " " << ID[i] << endl;
                break;
            }

    score = 101;
    for (int i = 0; i < n; i++)
        if (gender[i] == "M" && grade[i] < score)
            score = grade[i];
    g2 = score;
    if (score == 101) {
        printf("Absent\n");
        flag = true;
    } else
        for (int i = 0; i < n; i++)
            if (grade[i] == score) {
                cout << name[i] << " " << ID[i] << endl;
                break;
            }
    if (flag) {
        printf("NA\n");
        return 0;
    }
    printf("%d\n", abs(g1 - g2));
    return 0;
}