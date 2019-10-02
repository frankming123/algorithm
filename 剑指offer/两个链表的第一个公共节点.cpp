#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};
class Solution {
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        set<ListNode *> sset;
        while (pHead1) {
            sset.insert(pHead1);
            pHead1 = pHead1->next;
        }
        while (pHead2) {
            if (sset.find(pHead2) != sset.end())
                return pHead2;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
};
int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 0};
    cout << s.InversePairs(v);
    return 0;
}