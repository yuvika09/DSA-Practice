// At a time the frog can climb either one or two steps.Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]).

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int minJumpsMemo(int idx, vector<int> heights, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int jump1 = minJumpsMemo(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
    int jump2 = INT_MAX;
    if (idx > 1)
    {
        jump2 = minJumpsMemo(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
    }
    return dp[idx] = min(jump1, jump2);
}

int minJumpsTab(int n, vector<int> heights, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int jump1 = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int jump2 = INT_MAX;
        if (i > 1)
        {
            jump2 = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(jump1, jump2);
    }
    return dp[n - 1];
}

int minJumpsOptimized(int n, vector<int> heights)
{
    int prev2 = 0, prev = 0;
    int curr;
    for (int i = 1; i < n; i++)
    {
        int jump1 = prev + abs(heights[i] - heights[i - 1]);
        int jump2 = INT_MAX;
        if (i > 1)
        {
            jump2 = prev2 + abs(heights[i] - heights[i - 2]);
        }
        curr = min(jump1, jump2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    cout << minJumpsMemo(n - 1, height, dp1);
    cout << minJumpsTab(n, height, dp2);
    cout << minJumpsOptimized(n, height);
    return 0;
}