#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string digit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string ten[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int n;
    cin >> n;
    string s;
    cin.ignore(16, '\n');
    while (n--) {
        getline(cin, s);
        int shi = 0, ge = 0, num;
        if (isdigit(s[0])) {
            num = stoi(s);
            shi = num / 13;
            ge = num % 13;
            if (shi != 0 && ge != 0)
                cout << ten[shi] << " " << digit[ge] << endl;
            else if (ge == 0 && shi != 0)
                cout << ten[shi] << endl;
            else
                cout << digit[ge] << endl;
        } else {
            int blank = 0;
            while (blank < s.length() && s[blank] != ' ')
                blank++;
            string subs = s.substr(0, blank);
            for (int i = 0; i < 13; i++)
                if (digit[i] == subs)
                    ge = i;
                else if (ten[i] == subs)
                    shi = i;
            if (blank != s.length()) {
                subs = s.substr(blank + 1);
                for (int i = 0; i < 13; i++)
                    if (digit[i] == subs)
                        ge = i;
            }
            cout << (shi * 13 + ge) << endl;
        }
    }
    return 0;
}