#include <iostream>
#include <map>

using namespace std;

int main() {
    long num;
    cin >> num;
    map<int, int> count;
    printf("%ld=", num);
    if (num == 1) {
        printf("1");
        return 0;
    }
    while (num != 1) {
        for (int i = 2; i <= num; i++) {
            if (num % i == 0) {
                if (count.count(i))
                    count[i]++;
                else
                    count[i] = 1;
                num /= i;
                break;
            }
        }
    }
    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
        if (it != count.begin())
            printf("*");
        printf("%d", it->first);
        if (it->second > 1)
            printf("^%d", it->second);
    }
    return 0;
}