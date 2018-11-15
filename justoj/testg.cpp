#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> res;
    int n;
    cin >> n;
    list<int> array;
    while (n--) {
        char c;
        int bango;
        cin >> c >> bango;
        if (c == 'L')
            array.push_front(bango);
        else if (c == 'R')
            array.push_back(bango);
        else if (c == '?') {
            int len = 0, pos = 0;
            for (list<int>::iterator it = array.begin(); it != array.end();
                 it++) {
                if ((*it) == bango)
                    pos = len;
                len++;
            }
            res.push_back(min(pos, len - pos - 1));
        }
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}
