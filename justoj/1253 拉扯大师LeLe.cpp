#include <algorithm>
#include <iostream>

using namespace std;

int triangle[3];

int calc() {
    sort(triangle, triangle + 3);
    if (triangle[0] + triangle[1] > triangle[2])
        return 0;
    return triangle[2] - triangle[1] - triangle[0] + 1;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> triangle[0] >> triangle[1] >> triangle[2];
        cout << calc() << endl;
    }
    return 0;
}
