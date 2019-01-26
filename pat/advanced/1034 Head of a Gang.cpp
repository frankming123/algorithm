#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> calls;
map<string, set<string>> relations;
map<string, int> res;
set<string> passed;

string head;
int total;
int maxcall;
int nums;

void run(string now) {
    passed.insert(now);
    total += calls[now];
    nums++;
    if (calls[now] > maxcall) {
        maxcall = calls[now];
        head = now;
    }
    for (set<string>::iterator it = relations[now].begin(); it != relations[now].end(); it++)
        if (!passed.count(*it))
            run(*it);
}

int main() {
    int n, k;
    cin >> n >> k;
    string str1, str2;
    int time;
    while (n--) {
        cin >> str1 >> str2 >> time;
        if (calls.count(str1))
            calls[str1] += time;
        else
            calls[str1] = time;
        if (calls.count(str2))
            calls[str2] += time;
        else
            calls[str2] = time;
        relations[str1].insert(str2);
        relations[str2].insert(str1);
    }
    // for (map<string, int>::iterator it = calls.begin(); it != calls.end(); it++)
    //     cout << it->first << " " << it->second << endl;
    // for (map<string, set<string>>::iterator it = relations.begin(); it != relations.end(); it++) {
    //     cout << it->first << ":";
    //     for (set<string>::iterator sit = it->second.begin();
    //          sit != it->second.end(); sit++) {
    //         cout << " " << *sit;
    //     }
    //     cout << endl;
    // }

    for (map<string, int>::iterator it = calls.begin(); it != calls.end(); it++) {
        total = 0;
        maxcall = 0;
        nums = 0;
        if (!passed.count(it->first))
            run(it->first);
        if (total / 2 > k && nums > 2)
            res[head] = nums;
    }
    cout << res.size() << endl;
    for (map<string, int>::iterator it = res.begin(); it != res.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}