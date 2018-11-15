/*
1001 A+B Format （20 分）
Calculate a+b and output the sum in standard format -- that is, the digits must
be separated into groups of three by commas (unless there are less than four
digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a
and b where −10^​6 ≤a,b≤ 10^​6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum
must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  string str = to_string(a + b);
  bool isneg = str[0] == '-' ? true : false;
  int firstPos = str.length() % 3;
  if (firstPos == 0 || (isneg && firstPos == 1))
    firstPos += 3;
  for (int i = firstPos; i < str.length(); i += 3) {
    str = str.substr(0, i) + ',' + str.substr(i);
    i++;
  }
  cout << str;
  return 0;
}