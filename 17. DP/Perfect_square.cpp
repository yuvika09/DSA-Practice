// Given an integer n, return the least number of perfect square numbers that sum to n.

#include <bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    int count = 1;
    while (count * count <= n)
    {
        int sq = count * count;
        for (int i = 1; i <= sq; i++)
        {
            dp[i] = min(dp[i - sq], dp[i]);
        }
        count++;
    }
    return dp[n];
}