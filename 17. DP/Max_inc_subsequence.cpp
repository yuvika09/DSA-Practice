// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// Input: nums = [10,9,2,5,3,7,101,18]
//  Output: 4
//  Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 - Brute Force
// TC = O(2^n)    SC = O(N) - recursive stack

int solve1(vector<int> &nums, int i, int prev)
{
    if (i >= nums.size())
    {
        return 0;
    }
    int take = 0;
    int dontTake = solve1(nums, i + 1, prev);
    if (nums[i] > prev)
    {
        take = 1 + solve1(nums, i + 1, nums[i]);
    }
    return max(take, dontTake);
}

int lengthOfLIS(vector<int> &nums)
{
    return solve1(nums, 0, INT_MIN);
}

// APPROACH 2 - DP
// TC = O(n^2)    SC = O(n^2)

int solve2(vector<int> &nums, vector<vector<int>> &dp, int i, int prevIdx)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i][prevIdx + 1] != -1)
    {
        return dp[i][prevIdx + 1];
    }

    int take = 0;
    int dontTake = solve2(nums, dp, i + 1, prevIdx);
    if (prevIdx == -1 || nums[i] > nums[prevIdx])
    {
        take = 1 + solve2(nums, dp, i + 1, i);
    }
    return dp[i][prevIdx + 1] = max(take, dontTake);
}

int lengthOfLIS(vector<int> &nums)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    return solve2(nums, dp, 0, -1);
}

// APPROACH 3 - DP - memoization
// TC = O(n^2)    SC = O(n)

int solve2(vector<int> &nums, vector<int> &dp, int i, int prevIdx)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[prevIdx + 1] != -1)
    {
        return dp[prevIdx + 1];
    }

    int take = 0;
    int dontTake = solve2(nums, dp, i + 1, prevIdx);
    if (prevIdx == -1 || nums[i] > nums[prevIdx])
    {
        take = 1 + solve2(nums, dp, i + 1, i);
    }
    return dp[prevIdx + 1] = max(take, dontTake);
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return solve2(nums, dp, 0, -1);
}

// APPROACH 4 - DP - tabulation
// TC = O(n^2)    SC = O(n)

int lengthOfLIS(vector<int> &nums)
{
    int ans = 1, n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}

// APPROACH 5 - Binary Search
// TC = O(n log n)    SC = O(1)

int lengthOfLIS(vector<int> &nums)
{
    vector<int> temp;
    int len = 1;
    temp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); //subtracting first iterator to get the index
            temp[idx] = nums[i];
        }
    }
    return len;
}