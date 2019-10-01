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
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *root = new ListNode(0);
        while (pHead != NULL) {
            ListNode *next = pHead->next;
            pHead->next = root->next;
            root->next = pHead;
            pHead = next;
        }
        return root->next;
    }
};
int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    ListNode *res = s.ReverseList(root);
    cout << res->val << " " << res->next->val << " " << res->next->next->val << endl;
    return 0;
}