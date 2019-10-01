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
    vector<int> printListFromTailToHead(ListNode *head) {
        int len = 0;
        ListNode *now = head;
        while (now != NULL) {
            now = now->next;
            len++;
        }
        vector<int> v(len);
        for (int i = len - 1; i >= 0; i--) {
            v[i] = head->val;
            head = head->next;
        }
        return v;
    }
};

int main() {
    Solution s=Solution();
    return 0;
}