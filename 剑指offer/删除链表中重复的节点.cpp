#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};
class Solution {
  public:
    ListNode *deleteDuplication(ListNode *pHead) {
        ListNode *root = new ListNode(0);
        root->next = pHead;
        ListNode *now = root;
        while (now != NULL && now->next != NULL) {
            ListNode *tmp = now->next;
            int dup = tmp->val;
            int cnt = 0;
            while (tmp != NULL && tmp->val == dup) {
                tmp = tmp->next;
                cnt++;
            }
            if (cnt != 1)
                now->next = tmp;
            else
                now = now->next;
            // printf("now:%d cnt:%d tmp:%d\n", now->val, cnt, tmp == NULL ? -1 : tmp->val);
            // printf("now:%d", now->val);
            // ListNode *t = now->next;
            // while (t != NULL) {
            //     printf("->%d", t->val);
            //     t = t->next;
            // }
            // printf("\n");
        }
        // printf("root:%d", root->val);
        // ListNode *t = root->next;
        // while (t != NULL) {
        //     printf("->%d", t->val);
        //     t = t->next;
        // }
        // printf("\n");
        return root->next;
    }
};
int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next = new ListNode(5);
    ListNode *res = s.deleteDuplication(root);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}