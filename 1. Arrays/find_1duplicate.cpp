#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 - sorting O(NlogN), O(1)
int findDuplicate1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return nums[i];
        }
    }
    return -1;
}

// APPROACH 2 - hashing O(N), O(N)
int findDuplicate2(vector<int> &nums)
{
    int hash[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash[nums[i]] == 0)
        {
            hash[nums[i]]++;
        }
        else
        {
            return nums[i];
        }
    }
    return -1;
}

// APPROACH 2 - ll cycle detection O(N), O(1)
int findDuplicate3(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];
    slow = nums[slow];
    fast = nums[nums[fast]];
    while (slow != fast) // we can use do while also
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vector<int> nums{2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    cout << findDuplicate3(nums);
    return 0;
}