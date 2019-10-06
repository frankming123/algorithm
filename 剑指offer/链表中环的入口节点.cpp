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
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        ListNode *fast = pHead, *slow = pHead;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;
        fast = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    // root->next = new ListNode(2);
    // root->next->next = new ListNode(3);
    // root->next->next->next = new ListNode(4);
    // root->next->next->next->next = root->next;
    ListNode *res = s.EntryNodeOfLoop(root);
    if (res)
        cout << res->val;

    return 0;
}