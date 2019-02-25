#include <iostream>
#include <string>

using namespace std;

int cnt[128];

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++)
        cnt[s2[i]]++;

    for (int i = 0; i < s1.length(); i++)
        if (cnt[s1[i]] > 0)
            cnt[s1[i]]--;

    int count = 0;
    for (int i = 0; i < 128; i++)
        count += cnt[i];

    if (count > 0)
        printf("No %d", count);
    else
        printf("Yes %d", s1.length() - s2.length());
    return 0;
}