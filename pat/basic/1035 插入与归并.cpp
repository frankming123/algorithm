/*
1035 插入与归并 （25 分）
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1
个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1
个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：
输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N
个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：
首先在第 1 行中输出Insertion Sort表示插入排序、或Merge
Sort表示归并排序；然后在第 2
行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

输入样例 1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例 2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例 2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tmp[100];

bool issame = false;

void print(vector<int> &array) {
    cout << array[0];
    for (int i = 1; i < array.size(); i++) {
        cout << " " << array[i];
    }
}

bool compare(vector<int> &array1, vector<int> &array2) {
    int len = array1.size();
    for (int i = 0; i < len; i++) {
        if (array1[i] != array2[i])
            return false;
    }
    return true;
}

void insertSort(vector<int> &array, vector<int> &array2) {
    for (int i = 1; i < array.size(); i++) {
        for (int j = i; j >= 1 && array[j] < array[j - 1]; j--) {
            swap(array[j], array[j - 1]);
        }
        if (issame)
            return;
        if (compare(array, array2))
            issame = true;
    }
}

void merge(vector<int> &array, int left, int mid, int right) {
    int l = left, r = mid;
    for (int i = 0; i < right - left; i++) {
        if (l == mid) {
            tmp[i] = array[r];
            r++;
        } else if (r == right) {
            tmp[i] = array[l];
            l++;
        } else if (array[l] < array[r]) {
            tmp[i] = array[l];
            l++;
        } else {
            tmp[i] = array[r];
            r++;
        }
    }
    for (int i = 0; i < right - left; i++) {
        array[left + i] = tmp[i];
    }
}

void mergeSort(vector<int> &array, vector<int> &mid) {
    int interal = 2;
    for (interal = 2; interal < array.size() * 2; interal *= 2) {
        for (int i = 0; i <= array.size(); i += interal) {
            // merge(array, i, i + interal / 2, i + interal);
            sort(array.begin() + i,
                 array.begin() +
                     (i + interal > array.size() ? array.size() : i + interal));
        }
        if (issame)
            return;
        if (compare(array, mid))
            issame = true;
    }
    // merge(array, 0, interal / 2, array.size());
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> array(n);
    vector<int> middle(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    for (int i = 0; i < n; i++)
        cin >> middle[i];
    vector<int> tmp(array);
    insertSort(tmp, middle);
    if (issame) {
        cout << "Insertion Sort" << endl;
        print(tmp);
    } else {
        mergeSort(array, middle);
        cout << "Merge Sort" << endl;
        print(array);
    }
    return 0;
}
