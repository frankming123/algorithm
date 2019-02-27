#include <iostream>
#include <queue>

using namespace std;

bool array[100][100];

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int node, k, subnode;
        cin >> node >> k;
        while (k--) {
            cin >> subnode;
            array[node][subnode] = true;
        }
    }

    bool flag = false;
    queue<int> mq;
    mq.push(1);

    while (!mq.empty()) {
        int k = mq.size();
        int count = 0;
        while (k--) {
            int node = mq.front();
            bool isleaf = true;
            mq.pop();
            for (int i = 0; i < 100; i++)
                if (array[node][i]) {
                    mq.push(i);
                    isleaf = false;
                }
            if (isleaf)
                count++;
        }
        printf("%s%d", flag ? " " : "", count);
        flag = true;
    }

    return 0;
}
