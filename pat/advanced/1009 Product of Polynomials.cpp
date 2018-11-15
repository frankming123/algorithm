/*
1009 Product of Polynomials （25 分）
This time, you are supposed to find A×B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N
​1
​​  a
​N
​1
​​ 
​​  N
​2
​​  a
​N
​2
​​ 
​​  ... N
​K
​​  a
​N
​K
​​ 
​​ 

where K is the number of nonzero terms in the polynomial, N
​i
​​  and a
​N
​i
​​ 
​​  (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N
​K
​​ <⋯<N
​2
​​ <N
​1
​​ ≤1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output:
3 3 3.6 2 6.0 1 1.6
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    double array1[1001] = {0};
    double array2[1001] = {0};
    int n;
    cin >> n;
    while (n--) {
        int n;
        double a;
        cin >> n >> a;
        array1[n] = a;
    }
    cin >> n;
    while (n--) {
        int n;
        double a;
        cin >> n >> a;
        array2[n] = a;
    }

    double res[2001] = {0};

    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            res[i + j] += array1[i] * array2[j];

    int count = 0;
    for (int i = 0; i < 2001; i++)
        if (res[i] != 0)
            count++;

    printf("%d", count);

    for (int i = 2000; i >= 0; i--)
        if (res[i] != 0)
            printf(" %d %.1lf", i, res[i]);

    return 0;
}
