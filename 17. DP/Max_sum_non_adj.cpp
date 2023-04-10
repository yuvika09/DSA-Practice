// return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int maxSumMemo(int idx, vector<int> arr, vector<int> &dp)
{
    if (idx < 0)
    {
        return 0;
    }
    if (idx == 0)
    {
        return arr[idx];
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int pick = arr[idx] + maxSumMemo(idx - 2, arr, dp);
    int notPick = 0 + maxSumMemo(idx - 1, arr, dp);

    return dp[idx] = max(pick, notPick);
}

int maxSumTab(int n, vector<int> arr, vector<int> &dp)
{
    dp[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }

    return dp[n];
}

int maxSumOptimized(int n, vector<int> arr)
{
    int prev = arr[0];
    int prev2 = 0, curr;
    for (int i = 1; i <= n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notPick = 0 + prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    cout << maxSumMemo(n - 1, arr, dp1);
    cout << maxSumTab(n - 1, arr, dp2);
    cout << maxSumOptimized(n - 1, arr);
    return 0;
}