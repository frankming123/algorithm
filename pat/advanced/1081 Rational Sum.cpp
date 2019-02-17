#include <iostream>

using namespace std;

int n;

long num1, num2 = 1, integer, num3;
long input1, input2;

int commnum(int a, int b) {
    return b == 0 ? a : commnum(b, a % b);
}

void calc() {
    bool isNeg = false;
    num1 = num1 * input2 + num2 * input1;
    num2 *= input2;
    if (num1 < 0) {
        isNeg = true;
        num1 *= -1;
    }
    num3 = commnum(num1, num2);
    num1 /= num3;
    num2 /= num3;
    if (num1 >= num2) {
        integer += num1 / num2 * (isNeg ? (-1) : 1);
        num1 %= num2;
    }
    if (isNeg)
        num1 *= -1;
    // printf("num1: %d num2: %d integer: %d\n", num1, num2, integer);
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%ld/%ld", &input1, &input2);
        // printf("input1: %d input2: %d\n", input1, input2);
        calc();
    }
    if (integer == 0 && num1 == 0)
        printf("0");
    if (integer != 0)
        printf("%ld", integer);
    if (integer != 0 && num1 != 0)
        printf(" ");
    if (num1 != 0)
        printf("%ld/%ld", num1, num2);
    return 0;
}