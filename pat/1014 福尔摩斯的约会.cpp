#include <iostream>
#include <string>

using namespace std;

string judgeWeek(char);
string judgeHour(char);

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    char day, hour;
    bool isPassedA = false, isPassedB = false;
    for (int i = 0; i < a.length() && !isPassedB; i++) {
        if (a[i] == b[i]) {
            if (!isPassedA && a[i] >= 'A' && a[i] <= 'G') {
                isPassedA = true;
                day = a[i];
            } else if (isPassedA && ((a[i] >= 'A' && a[i] <= 'N') ||
                                     (a[i] >= '0' && a[i] <= '9'))) {
                isPassedB = true;
                hour = a[i];
            }
        }
    }
    int i;
    for (i = 0; i < c.length(); i++) {
        if (c[i] == d[i] &&
            ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))) {
            break;
        }
    }
    cout << judgeWeek(day) << " " << judgeHour(hour) << ":";
    if (i < 10)
        cout << "0";
    cout << i;
    return 0;
}

string judgeWeek(char c) {
    if (c == 'A')
        return "MON";
    if (c == 'B')
        return "TUE";
    if (c == 'C')
        return "WED";
    if (c == 'D')
        return "THU";
    if (c == 'E')
        return "FRI";
    if (c == 'F')
        return "SAT";
    if (c == 'G')
        return "SUN";
    return "judege week wrong!";
}

string judgeHour(char c) {
    if (c == '0')
        return "00";
    if (c == '1')
        return "01";
    if (c == '2')
        return "02";
    if (c == '3')
        return "03";
    if (c == '4')
        return "04";
    if (c == '5')
        return "05";
    if (c == '6')
        return "06";
    if (c == '7')
        return "07";
    if (c == '8')
        return "08";
    if (c == '9')
        return "09";
    if (c == 'A')
        return "10";
    if (c == 'B')
        return "11";
    if (c == 'C')
        return "12";
    if (c == 'D')
        return "13";
    if (c == 'E')
        return "14";
    if (c == 'F')
        return "15";
    if (c == 'G')
        return "16";
    if (c == 'H')
        return "17";
    if (c == 'I')
        return "18";
    if (c == 'J')
        return "19";
    if (c == 'K')
        return "20";
    if (c == 'L')
        return "21";
    if (c == 'M')
        return "22";
    if (c == 'N')
        return "23";
    return "judge hour wrong!";
}