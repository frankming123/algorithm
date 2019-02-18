#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, m;

struct stu {
    string id;
    int score;
} stus[10000];

struct use2 {
    int cnt;
    int total;
};

struct use3 {
    string site;
    int cnt;
};

bool cmp1(stu &a, stu &b) {
    if (a.score == b.score)
        return a.id < b.id;
    return a.score > b.score;
}
bool cmp2(use3 &a, use3 &b) {
    if (a.cnt == b.cnt)
        return a.site < b.site;
    return a.cnt > b.cnt;
}

int main() {
    cin >> n >> m;
    string id;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> stus[i].id >> stus[i].score;
    }
    vector<vector<stu>> type1(3, vector<stu>());
    map<string, use2> type2;
    map<string, map<string, int>> type3;
    for (int i = 0; i < n; i++) {
        char level = stus[i].id[0];
        string site = stus[i].id.substr(1, 3);
        string date = stus[i].id.substr(4, 6);

        if (level == 'B')
            type1[0].push_back(stus[i]);
        else if (level == 'A')
            type1[1].push_back(stus[i]);
        else if (level == 'T')
            type1[2].push_back(stus[i]);
        if (type2.find(site) == type2.end()) {
            type2[site] = use2{1, stus[i].score};
        } else {
            type2[site].cnt++;
            type2[site].total += stus[i].score;
        }
        if (type3.find(date) == type3.end()) {
            type3[date][site] = 1;
        } else if (type3[date].find(site) == type3[date].end()) {
            type3[date][site] = 1;
        } else {
            type3[date][site]++;
        }
    }

    for (int i = 0; i < 3; i++)
        sort(type1[i].begin(), type1[i].end(), cmp1);

    map<string, vector<use3>> v3;
    for (map<string, map<string, int>>::iterator it1 = type3.begin(); it1 != type3.end(); it1++) {
        v3[it1->first] = vector<use3>(it1->second.size());
        map<string, int>::iterator it2 = it1->second.begin();
        for (int i = 0; i < v3[it1->first].size(); i++) {
            v3[it1->first][i] = use3{it2->first, it2->second};
            it2++;
        }
    }
    for (map<string, vector<use3>>::iterator it = v3.begin(); it != v3.end(); it++)
        sort(it->second.begin(), it->second.end(), cmp2);

    int type;
    string term;
    for (int i = 1; i <= m; i++) {
        cin >> type >> term;
        cout << "Case " << i << ": " << type << " " << term << endl;
        if (type == 1) {
            int tmp;
            if (term == "A")
                tmp = 1;
            if (term == "B")
                tmp = 0;
            if (term == "T")
                tmp = 2;
            for (int j = 0; j < type1[tmp].size(); j++)
                cout << type1[tmp][j].id << " " << type1[tmp][j].score << endl;
            if (type1[tmp].size() == 0)
                cout << "NA" << endl;
        } else if (type == 2) {
            if (type2.find(term) != type2.end())
                cout << type2[term].cnt << " " << type2[term].total << endl;
            else
                cout << "NA" << endl;
        } else if (type == 3) {
            if (v3.find(term) != v3.end()) {
                for (int j = 0; j < v3[term].size(); j++)
                    cout << v3[term][j].site << " " << v3[term][j].cnt << endl;
            } else
                cout << "NA" << endl;
        }
    }

    // for (int i = 0; i < 3; i++)
    // for (int j = 0; j < type1[i].size(); j++)
    // cout << type1[i][j].id << " " << type1[i][j].score << endl;
    return 0;
}