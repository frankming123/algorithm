/*
1003 Emergency （25 分）
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C
​1
​​  and C
​2
​​  - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c
​1
​​ , c
​2
​​  and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C
​1
​​  to C
​2
​​ .

Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C
​1
​​  and C
​2
​​ , and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/
#include <iostream>
#include <vector>

using namespace std;

void todo(vector<vector<int>> &instance, vector<int> &rescue, int nowcity,
          int nowpath, int nowrescue, int goalcity, vector<int> &pathlen,
          vector<int> &rescuelen, vector<int> &passedcity) {
    if (nowcity == goalcity) {
        pathlen.push_back(nowpath);
        rescuelen.push_back(nowrescue);
        return;
    }
    for (int i = 0; i < instance[nowcity].size(); i++) {
        if (instance[nowcity][i] != -1 && passedcity[i] == 0) {
            passedcity[i] = 1;
            todo(instance, rescue, i, instance[nowcity][i] + nowpath,
                 rescue[i] + nowrescue, goalcity, pathlen, rescuelen,
                 passedcity);
            passedcity[i] = 0;
        }
    }
    return;
}

/*
instance:save instances between any two cities
rescue: save helper people of every city
pathlen: save all the lengths between c1 and c2
rescuelen: save all the helper people can called between c1 and c2
passedcity: save the cities that has passed, avoid duplicate
*/
int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;

    vector<int> rescue(n);
    for (int i = 0; i < n; i++)
        cin >> rescue[i];
    vector<vector<int>> instance(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        instance[tmp1][tmp2] = tmp3;
        instance[tmp2][tmp1] = tmp3;
    }

    vector<int> pathlen, rescuelen;
    vector<int> passedcity(n, 0);
    passedcity[c1] = 1;
    todo(instance, rescue, c1, 0, rescue[c1], c2, pathlen, rescuelen,
         passedcity);

    int minpath = pathlen[0], maxrescue = 0, minpathnum = 0;

    for (int i = 0; i < pathlen.size(); i++)
        minpath = pathlen[i] < minpath ? pathlen[i] : minpath;

    for (int i = 0; i < pathlen.size(); i++)
        if (pathlen[i] == minpath) {
            maxrescue = rescuelen[i] > maxrescue ? rescuelen[i] : maxrescue;
            minpathnum++;
        }

    cout << minpathnum << " " << maxrescue << endl;

    return 0;
}
