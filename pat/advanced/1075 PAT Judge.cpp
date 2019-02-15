#include <algorithm>
#include <iostream>

using namespace std;

int n, k, m;

int problem[6];

struct stu {
    int id;
    int ques[5];
    int cnt;
    int total;
} score[100001];

bool cmp(stu &a, stu &b) {
    if (a.id < 0)
        return false;
    if (b.id < 0)
        return true;

    if (a.total == b.total) {
        if (a.cnt == b.cnt)
            return a.id < b.id;
        return a.cnt > b.cnt;
    }
    return a.total > b.total;
}

int main() {
    for (int i = 0; i < 100001; i++) {
        score[i].id = -1;
        fill(score[i].ques, score[i].ques + 5, -1);
        score[i].total = 0;
        score[i].cnt = 0;
    }
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++)
        cin >> problem[i];
    int tmp1, tmp2, tmp3;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp2--;
        score[tmp1].id = tmp1;
        if ((score[tmp1].ques[tmp2] == -1 || score[tmp1].ques[tmp2] == -2) && tmp3 == -1)
            score[tmp1].ques[tmp2] = -2;
        else if (score[tmp1].ques[tmp2] < tmp3)
            score[tmp1].ques[tmp2] = tmp3;
    }
    for (int i = 0; i < 100001; i++) {
        if (score[i].id != -1) {
            bool flag = false;
            for (int j = 0; j < k; j++) {
                if (score[i].ques[j] != -2 && score[i].ques[j] != -1) {
                    flag = true;
                    score[i].total += score[i].ques[j];
                    if (score[i].ques[j] == problem[j])
                        score[i].cnt++;
                }
            }
            if (!flag)
                score[i].id = -1;
        }
    }

    sort(score, score + 100001, cmp);

    int rank = 1;
    for (int i = 0; i < 100001 && score[i].id != -1; i++) {
        if (i != 0 && score[i].total != score[i - 1].total)
            rank = i + 1;
        printf("%d %05d %d", rank, score[i].id, score[i].total);
        for (int j = 0; j < k; j++) {
            if (score[i].ques[j] == -1)
                printf(" -");
            else if (score[i].ques[j] == -2)
                printf(" 0");
            else
                printf(" %d", score[i].ques[j]);
        }
        //printf(" %d", score[i].cnt);
        printf("\n");
    }

    return 0;
}