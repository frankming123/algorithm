/*
1014 Waiting in Line （30 分）
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer
​i
​​  will take T
​i
​​  minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer
​1
​​  is served at window
​1
​​  while customer
​2
​​  is served at window
​2
​​ . Customer
​3
​​  will wait in front of window
​1
​​  and customer
​4
​​  will wait in front of window
​2
​​ . Customer
​5
​​  will wait behind the yellow line.

At 08:01, customer
​1
​​  is done and customer
​5
​​  enters the line in front of window
​1
​​  since that line seems shorter now. Customer
​2
​​  will leave at 08:02, customer
​4
​​  at 08:06, customer
​3
​​  at 08:07, and finally customer
​5
​​  at 08:10.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line), K (≤1000, number of customers), and Q (≤1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

Sample Input:
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output:
08:07
08:06
08:10
17:00
Sorry
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct person {
    int num;
    int needtime;
    int timestamp;
    int ntime;
};

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<person>> queues(n);
    queue<person> other;

    int temp;
    int num = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (num++ < k) {
                cin >> temp;
                queues[j].push_back(person{num, temp, 0, temp});
            }

    while (num++ < k) {
        cin >> temp;
        other.push(person{num, temp, 0, temp});
    }

    int tim = 0;
    vector<person> res(k + 1);
    bool isempty = false;
    while (!isempty) {
        int firstp = 10240;
        for (int i = 0; i < queues.size(); i++)
            if (!queues[i].empty())
                firstp = queues[i][0].needtime < firstp ? queues[i][0].needtime
                                                        : firstp;
        tim += firstp;
        bool flag = false;
        for (int i = 0; i < queues.size(); i++)
            if (queues[i].empty())
                continue;
            else if (!flag && queues[i][0].needtime == firstp) {
                flag = true;
                queues[i][0].timestamp = tim;
                res[queues[i][0].num] = queues[i][0];
                queues[i].erase(queues[i].begin());
                if (!other.empty()) {
                    queues[i].push_back(other.front());
                    other.pop();
                }
            } else
                queues[i][0].needtime -= firstp;
        bool isisempty = true;
        for (int i = 0; i < queues.size(); i++)
            if (!queues[i].empty()) {
                isisempty = false;
                break;
            }
        if (isisempty)
            isempty = true;
    }

    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        if (res[num].timestamp - res[num].ntime >= 540)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", res[num].timestamp / 60 + 8,
                   res[num].timestamp % 60);
    }

    return 0;
}
