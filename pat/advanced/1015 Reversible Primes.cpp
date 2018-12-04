/*
1015 Reversible Primes （20 分）
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10
​5
​​ ) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
*/
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    int nsqrt = sqrt(num);
    for (int i = 2; i <= nsqrt; i++)
        if (num % i == 0)
            return false;
    return true;
}

int itos(string &s, int base) {
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        res += int(s[i] - '0') * pow(base, i - s.length() + 1);
    }
    return res;
}

bool calc(int num, int base) {
    if (!isPrime(num))
        return false;
    stringstream sstream;
    while (num != 0) {
        sstream << (num % base);
        num /= base;
    }
    string s = sstream.str();
    if (!isPrime(stoi(s, nullptr, base)))
        return false;
    return true;
}

int main(int argc, char const *argv[]) {
    int num, base;
    while (true) {
        cin >> num;
        if (num < 0)
            break;
        cin >> base;
        cout << (calc(num, base) ? "Yes" : "No") << endl;
    }
    return 0;
}
