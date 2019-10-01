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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        ListNode *next = pListHead;
        while (k--) {
            if (next == NULL)
                return NULL;
            next = next->next;
        }
        while (next != NULL) {
            pListHead = pListHead->next;
            next = next->next;
        }

        return pListHead;
    }
};
int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    cout << s.FindKthToTail(root, 3)->val;
    return 0;
}