#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {
    }
};
class Solution {
  public:
    map<RandomListNode *, RandomListNode *> mmap;
    void run(RandomListNode *pHead) {
        if (mmap.find(pHead) == mmap.end()) {
            RandomListNode *tmp = new RandomListNode(pHead->label);
            mmap[pHead] = tmp;
        }
    }
    RandomListNode *Clone(RandomListNode *pHead) {
        if (pHead == NULL)
            return NULL;
        RandomListNode *res = pHead;
        while (pHead != NULL) {
            run(pHead);
            if (pHead->next != NULL) {
                run(pHead->next);
                mmap[pHead]->next = mmap[pHead->next];
            }
            if (pHead->random != NULL) {
                run(pHead->random);
                mmap[pHead]->random = mmap[pHead->random];
            }
            pHead = pHead->next;
        }
        return mmap[res];
    }
};
int main() {
    Solution s;
    RandomListNode *root = new RandomListNode(1);
    root->next=new RandomListNode(2);
    RandomListNode *res = s.Clone(root);
    while (res) {
        printf("%d\n", res->label);
        res = res->next;
    }
    return 0;
}