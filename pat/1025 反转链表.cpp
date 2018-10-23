/*
it can not be passed-.-, but I can't find what is wrong
*/
#include <iostream>

using namespace std;

struct node {
    int val;
    int next;
};

node array[100002];

void reverse(int rev, int root) {
    int tmp = array[rev].next;
    array[rev].next = array[root].next;
    array[root].next = array[array[root].next].next;
    array[array[rev].next].next = tmp;
}

void travel(int root) {
    while (true) {
        if (array[root].next == -1) {
            printf("%05d %d -1", root, array[root].val);
            break;
        } else {
            printf("%05d %d %05d\n", root, array[root].val, array[root].next);
        }
        root = array[root].next;
    }
}

int main() {
    int n, k;
    cin >> array[100000].next >> n >> k;
    int address;
    for (int i = 0; i < n; i++) {
        cin >> address >> array[address].val >> array[address].next;
        //scanf("%d", &address);
        //scanf("%d %d", &array[address].val, &array[address].next);
    }
    array[100001].next = -1;
    int rev = 100001;
    int count = n / k;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < k; j++) {
            reverse(rev, 100000);
        }
        for (int j = 0; j < k; j++) {
            rev = array[rev].next;
        }
    }
    array[rev].next = array[100000].next;

    travel(array[100001].next);
    return 0;
}
