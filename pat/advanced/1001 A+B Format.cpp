#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    string str = to_string(a + b);
    bool isneg = str[0] == '-' ? true : false;
    int firstPos = str.length() % 3;
    if (firstPos == 0 || (isneg && firstPos == 1))
        firstPos += 3;
    for (int i = firstPos; i < str.length(); i += 3)
    {
        str = str.substr(0, i) + ',' + str.substr(i);
        i++;
    }
    cout << str;
    return 0;
}