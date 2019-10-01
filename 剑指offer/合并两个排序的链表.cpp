#include <cstdio>
#include <iostream>
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        ListNode *root = new ListNode(0);
        ListNode *now = root;
        while (pHead1 != NULL || pHead2 != NULL) {
            // printf("%d %d\n", pHead1 == NULL ? -1 : pHead1->val, pHead2 == NULL ? -1 : pHead2->val);
            if (pHead1 == NULL || (pHead2 != NULL && pHead1->val > pHead2->val)) {
                now->next = pHead2;
                now = now->next;
                pHead2 = pHead2->next;
            } else {
                now->next = pHead1;
                now = now->next;
                pHead1 = pHead1->next;
            }
        }
        return root->next;
    }
};
int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    ListNode *root1 = new ListNode(2);
    root1->next = new ListNode(3);
    root1->next->next = new ListNode(4);
    ListNode *res = s.Merge(root, NULL);
    while (res != NULL) {
        printf("%d ", res->val);
        res = res->next;
    }
    return 0;
}