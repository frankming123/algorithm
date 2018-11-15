#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> nums(1001, 0);
    int len, a;
    double b;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> a >> b;
        nums[a] += b;
    }
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> a >> b;
        nums[a] += b;
    }

    int count = 0;
    for (double i : nums)
        if (i != 0)
            count++;
    cout << count;
    for (int i = nums.size() - 1; i >= 0; i--)
        if (nums[i] != 0.0)
            printf(" %d %.1lf", i, nums[i]);
    return 0;
}