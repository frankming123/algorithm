/*
1013 Battle Over Cities （25 分）
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city
​1
​​ -city
​2
​​  and city
​1
​​ -city
​3
​​ . Then if city
​1
​​  is occupied by the enemy, we must have 1 highway repaired, that is the highway city
​2
​​ -city
​3
​​ .

Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input:
3 2 3
1 2
1 3
1 2 3
Sample Output:
1
0
0
*/
#include <iostream>

using namespace std;

int n;
bool array[1000][1000];
bool ispassed[1000];

void initispassed() {
    for (int i = 1; i <= n; i++)
        ispassed[i] = false;
}
void countcity(int city, int breakcity) {
    ispassed[city] = true;
    for (int i = 1; i <= n; i++)
        if (i != breakcity && i != city && array[city][i] && !ispassed[i])
            countcity(i, breakcity);
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int m, k;
    cin >> n >> m >> k;

    while (m--) {
        int a, b;
        cin >> a >> b;
        array[a][b] = true;
        array[b][a] = true;
    }

    while (k--) {
        int breakcity;
        cin >> breakcity;
        initispassed();
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!ispassed[i] && i != breakcity) {
                countcity(i, breakcity);
                count++;
            }
        }
        cout << (count - 1) << endl;
    }
    return 0;
}
