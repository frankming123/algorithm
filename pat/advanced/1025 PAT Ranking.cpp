#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct testee {
    string id;
    int grade;
    int lnum;
    int lrank;
    int frank;
} testees[30000];

bool cmp(testee &a, testee &b) {
    // return a.grade > b.grade;
    if (a.grade > b.grade)
        return true;
    if (a.grade == b.grade)
        return a.id < b.id;
    return false;
}

int main(int argc, char const *argv[]) {
    int n, k, grade, pos = 0;
    string id;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        int begin = pos;
        for (int j = 0; j < k; j++) {
            cin >> id >> grade;
            testees[pos++] = testee{id, grade, i};
        }
        int end = pos;
        sort(testees + begin, testees + end, cmp);
        for (int j = 0; j < k; j++) {
            if (j > 0 &&
                testees[begin + j].grade == testees[begin + j - 1].grade)
                testees[begin + j].lrank = testees[begin + j - 1].lrank;
            else
                testees[begin + j].lrank = j + 1;
        }
    }

    sort(testees, testees + pos, cmp);
    for (int i = 0; i < pos; i++) {
        if (i > 0 && testees[i].grade == testees[i - 1].grade)
            testees[i].frank = testees[i - 1].frank;
        else
            testees[i].frank = i + 1;
    }

    cout << pos << endl;
    for (int i = 0; i < pos; i++)
        cout << testees[i].id << " " << testees[i].frank << " "
             << testees[i].lnum << " " << testees[i].lrank << endl;

    return 0;
}
