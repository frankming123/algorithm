#include <iostream>
#include <vector>

using namespace std;

int n;
int tree[1001];

vector<int> nodes;

bool isMin, isMax;

void printTree(int root) {
    nodes.push_back(tree[root]);
    if (root * 2 > n) {
        for (int i = 0; i < nodes.size(); i++) {
            if (i != 0) {
                cout << " ";
                if (nodes[i] < nodes[i - 1])
                    isMax = true;
                else if (nodes[i] > nodes[i - 1])
                    isMin = true;
            }
            cout << nodes[i];
        }
        cout << endl;
    }
    if (root * 2 + 1 <= n)
        printTree(root * 2 + 1);
    if (root * 2 <= n)
        printTree(root * 2);
    nodes.pop_back();
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> tree[i];
    printTree(1);
    if (isMin && isMax)
        cout << "Not Heap" << endl;
    else if (isMin)
        cout << "Min Heap" << endl;
    else if (isMax)
        cout << "Max Heap" << endl;
    return 0;
}