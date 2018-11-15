/*
1012 The Best Rank （25 分）
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct stu {
    string id;
    int c;
    int m;
    int e;
    int a;
    int crank;
    int mrank;
    int erank;
    int arank;
};

bool atop(stu &a, stu &b) { return a.a > b.a; }
bool ctop(stu &a, stu &b) { return a.c > b.c; }
bool mtop(stu &a, stu &b) { return a.m > b.m; }
bool etop(stu &a, stu &b) { return a.e > b.e; }
void ranka(vector<stu> &a) {
    sort(a.begin(), a.end(), atop);
    a[0].arank = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].a == a[i - 1].a)
            a[i].arank = a[i - 1].arank;
        else
            a[i].arank = i + 1;
    }
}
void rankc(vector<stu> &a) {
    sort(a.begin(), a.end(), ctop);
    a[0].crank = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].c == a[i - 1].c)
            a[i].crank = a[i - 1].crank;
        else
            a[i].crank = i + 1;
    }
}
void rankm(vector<stu> &a) {
    sort(a.begin(), a.end(), mtop);
    a[0].mrank = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].m == a[i - 1].m)
            a[i].mrank = a[i - 1].mrank;
        else
            a[i].mrank = i + 1;
    }
}
void ranke(vector<stu> &a) {
    sort(a.begin(), a.end(), etop);
    a[0].erank = 1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].e == a[i - 1].e)
            a[i].erank = a[i - 1].erank;
        else
            a[i].erank = i + 1;
    }
}
void autorank(vector<stu> &a) {
    ranka(a);
    rankc(a);
    rankm(a);
    ranke(a);
}

void printrank(stu &a) {
    int toprank = a.arank;
    toprank = a.crank < toprank ? a.crank : toprank;
    toprank = a.mrank < toprank ? a.mrank : toprank;
    toprank = a.erank < toprank ? a.erank : toprank;
    cout << toprank << " ";
    if (toprank == a.arank)
        cout << "A";
    else if (toprank == a.crank)
        cout << "C";
    else if (toprank == a.mrank)
        cout << "M";
    else if (toprank == a.erank)
        cout << "E";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<stu> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i].id >> array[i].c >> array[i].m >> array[i].e;
        array[i].a = (array[i].c + array[i].m + array[i].e) / 3;
    }
    autorank(array);

    map<string, stu> stumap;
    for (int i = 0; i < n; i++)
        stumap[array[i].id] = array[i];

    string input;
    while (m--) {
        cin >> input;
        map<string, stu>::iterator it = stumap.find(input);
        if (it != stumap.end())
            printrank((*it).second);
        else
            cout << "N/A" << endl;
    }

    return 0;
}
