/*
according to comments on the Internet, this question is not really good.
I could only pass 11 tests in all 20 tests.
*/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string n1, n2;
    long tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    int num1, num2;
    num1 = stol(tag == 1 ? n1 : n2, nullptr, radix);

    for (int i = 2; i <= 36; i++) {
        try {
            num2 = stol(tag == 1 ? n2 : n1, nullptr, i);
        } catch (std::invalid_argument) {
            continue;
        }
        if (num2 > num1) {
            printf("Impossible");
            return 0;
        } else if (num2 == num1) {
            printf("%d", i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}
