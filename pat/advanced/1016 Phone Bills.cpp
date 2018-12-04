/*
1016 Phone Bills （25 分）
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB
*/
//do not print phone bill of who does not have any bill!!!
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int cost[24];

struct bill {
    string name;
    int month;
    int day;
    int hour;
    int minute;
    int status;
};

bool inorder(bill &a, bill &b) {
    if (a.name < b.name)
        return true;
    if (a.name == b.name && a.day < b.day)
        return true;
    if (a.name == b.name && a.day == b.day && a.hour < b.hour)
        return true;
    if (a.name == b.name && a.day == b.day && a.hour == b.hour &&
        a.minute < b.minute)
        return true;
    return false;
}

int useTime(bill &a, bill &b) {
    int count = 0;
    int d = a.day, h = a.hour, m = a.minute;
    while (d != b.day || h != b.hour || m != b.minute) {
        count++;
        if (m == 59) {
            if (h == 23) {
                d++;
                h = 0;
            } else
                h++;
            m = 0;
        } else
            m++;
    }

    return count;
}
int useMoney(bill &a, bill &b) {
    int d = a.day, h = a.hour, m = a.minute;
    int money = 0;
    while (d != b.day || h != b.hour || m != b.minute) {
        money += cost[h];
        if (m == 59) {
            if (h == 23) {
                d++;
                h = 0;
            } else
                h++;
            m = 0;
        } else
            m++;
    }
    return money;
}

void print(bill *bills, int num) {
    int pos = 0;
    while (pos != num) {
        cout << bills[pos].name;
        printf(" %02d:%02d:%02d %s\n", bills[pos].day, bills[pos].hour,
               bills[pos].minute, bills[pos].status ? "on-line" : "off-line");
        pos++;
    }
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 24; i++)
        cin >> cost[i];

    int n;
    string tmps;
    cin >> n;
    bill bills[n];
    for (int i = 0; i < n; i++) {
        cin >> bills[i].name;
        scanf("%d:%d:%d:%d", &bills[i].month, &bills[i].day, &bills[i].hour,
              &bills[i].minute);
        cin >> tmps;
        bills[i].status = tmps == "on-line" ? 1 : 0;
    }

    sort(bills, bills + n, inorder);

    string name = bills[0].name;
    int total = 0;
    bool flag = false;

    for (int i = 0; i < n - 1; i++) {
        if (bills[i].name != name) {
            if (flag)
                printf("Total amount: $%.2f\n", total / float(100));
            name = bills[i].name;
            flag = false;
            total = 0;
        }
        if (bills[i].name == bills[i + 1].name && bills[i].status == 1 &&
            bills[i + 1].status == 0) {
            if (!flag) {
                cout << bills[i].name;
                printf(" %02d\n", bills[i].month);
                flag = true;
            }
            int usemoney = useMoney(bills[i], bills[i + 1]);
            total += usemoney;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", bills[i].day,
                   bills[i].hour, bills[i].minute, bills[i + 1].day,
                   bills[i + 1].hour, bills[i + 1].minute,
                   useTime(bills[i], bills[i + 1]), usemoney / float(100));
        }
    }
    if (flag)
        printf("Total amount: $%.2f\n", total / float(100));

    return 0;
}
