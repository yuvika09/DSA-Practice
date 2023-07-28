// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size(), i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            break;
        }
    }
    if (i < 0)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (j = n - 1; j > i; j--)
    {
        if (nums[j] > nums[i])
        {
            break;
        }
    }
    swap(nums[j], nums[i]);
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> nums{1, 3, 5, 4, 2};
    nextPermutation(nums);
    for (auto i : nums)
    {
        cout << i;
    }
}