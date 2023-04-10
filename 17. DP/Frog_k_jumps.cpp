// At a time the frog can climb either one or two steps.Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int minJumpsMemo(int idx, int k, vector<int> heights, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int min_steps = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            int jump = minJumpsMemo(idx - i, k, heights, dp) + abs(heights[idx] - heights[idx - i]);
            min_steps = min(min_steps, jump);
        }
    }
    return dp[idx] = min_steps;
}

int minJumpsTab(int n, int k, vector<int> heights, vector<int> &dp)
{
    dp[0] = 0;

    for (int idx = 1; idx < n; idx++)
    {
        int min_steps = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (idx - i >= 0)
            {
                int jump = dp[idx - i] + abs(heights[idx] - heights[idx - i]);
                min_steps = min(min_steps, jump);
            }
        }
        dp[idx] = min_steps;
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    cout << minJumpsMemo(n - 1, k, height, dp1);
    cout << minJumpsTab(n, k, height, dp2);
    return 0;
}