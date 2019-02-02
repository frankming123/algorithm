#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> tree(1024);
bool isBST = true;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

vector<int> run1(int l, int r) {
    //printf("l: %d r: %d tree[l]: %d\n", l, r, tree[l]);
    if (!isBST || r == l)
        return vector<int>();
    if (r - l == 1)
        return vector<int>(1, tree[l]);
    int pos = l;
    bool flag = false;
    for (int i = l + 1; i < r; i++)
        if (!flag && tree[i] >= tree[l]) {
            pos = i;
            flag = true;
        } else if (flag && tree[i] < tree[l]) {
            isBST = false;
            return vector<int>();
        }
    //printf("l: %d r: %d pos: %d\n", l, r, pos);

    vector<int> left = run1(l + 1, pos);
    vector<int> right = run1(pos, r);
    vector<int> res;
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(tree[l]);
    //print(res);
    return res;
}

vector<int> run2(int l, int r) {
    //printf("l: %d r: %d tree[l]: %d\n", l, r, tree[l]);
    if (!isBST || r == l)
        return vector<int>();
    if (r - l == 1)
        return vector<int>(1, tree[l]);
    int pos = l;
    bool flag = false;
    for (int i = l + 1; i < r; i++)
        if (!flag && tree[i] < tree[l]) {
            pos = i;
            flag = true;
        } else if (flag && tree[i] >= tree[l]) {
            isBST = false;
            return vector<int>();
        }
    //printf("l: %d r: %d pos: %d\n", l, r, pos);

    vector<int> left = run2(l + 1, pos);
    vector<int> right = run2(pos, r);
    vector<int> res;
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    res.push_back(tree[l]);
    //print(res);
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    vector<int> res = run1(0, n);
    if (!isBST) {
        isBST = true;
        res = run2(0, n);
        if (!isBST) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    bool flag = false;
    for (int i = 0; i < res.size(); i++) {
        cout << (flag ? " " : "") << res[i];
        flag = true;
    }
    return 0;
}