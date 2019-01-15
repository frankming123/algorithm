#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp1, tmp2;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
    printf("\n");
}

void run(vector<vector<int>> &bin, vector<int> post, vector<int> in,
         int level) {
    // printf("level: %d ", level);
    // printf("post: size(%d) ", post.size());
    // print(post);
    // printf("in: size(%d) ", in.size());
    // print(in);
    if (post.size() == 0 || in.size() == 0)
        return;
    if (bin.size() < level + 1)
        bin.push_back(vector<int>());

    bin[level].push_back(post[post.size() - 1]);
    int pos;
    for (int i = 0; i < in.size(); i++)
        if (in[i] == post[post.size() - 1]) {
            pos = i;
            break;
        }
    // printf("pos: %d\n", pos);
    tmp1.assign(post.begin(), post.begin() + pos);
    tmp2.assign(in.begin(), in.begin() + pos);
    run(bin, tmp1, tmp2, level + 1);
    // printf("start---\n");
    tmp1.assign(post.begin() + pos, post.end() - 1);
    tmp2.assign(in.begin() + pos + 1, in.end());
    // printf("end---\n");
    run(bin, tmp1, tmp2, level + 1);
    // printf("over---\n");
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> post(n), in(n);
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];

    vector<vector<int>> bin;
    run(bin, post, in, 0);

    bool flag = false;
    for (int i = 0; i < bin.size(); i++)
        for (int j = 0; j < bin[i].size(); j++) {
            printf("%s%d", flag ? " " : "", bin[i][j]);
            flag = true;
        }
    return 0;
}
