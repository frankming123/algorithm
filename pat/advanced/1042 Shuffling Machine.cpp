#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> trans(55);
    cin >> n;
    for (int i = 1; i < 55; i++)
        cin >> trans[i];

    vector<int> cards(55);
    for (int i = 1; i < 55; i++)
        cards[i] = i;
    while (n--) {
        vector<int> tmp(55);
        for (int i = 1; i < 55; i++)
            tmp[trans[i]] = cards[i];
        cards.assign(tmp.begin(), tmp.end());
    }

    for (int i = 1; i < 55; i++) {
        int n = (cards[i] - 1) / 13;
        int m = (cards[i] - 1) % 13;
        if (i != 1)
            printf(" ");

        if (n == 0)
            printf("S");
        else if (n == 1)
            printf("H");
        else if (n == 2)
            printf("C");
        else if (n == 3)
            printf("D");
        else if (n == 4)
            printf("J");

        printf("%d", m + 1);
    }
    return 0;
}