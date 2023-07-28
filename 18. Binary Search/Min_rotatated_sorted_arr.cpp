//Finding minimum element in a rotated and sorted array.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1, mini = INT_MAX;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] > nums[mid])
        {
            mini = min(mini, nums[mid]);
            high = mid - 1;
        }
        else
        {
            mini = min(mini, nums[low]);
            low = mid + 1;
        }
    }
    return mini;
}