// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
//  "AAJF" with the grouping (1 1 10 6)
//  "KJF" with the grouping (11 10 6)
//  Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

#include <bits/stdc++.h>
using namespace std;

// Simple Recursion
int nWays(int idx, string s)
{
    int n = s.size();
    if (idx == n)
    {
        return 1;
    }
    else if (s[idx] == '0')
    {
        return 0;
    }
    if ((idx < n - 1) && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] < '7')))
    {
        return nWays(idx + 1, s) + nWays(idx + 2, s);
    }
    return nWays(idx + 1, s);
}

int numDecodings(string s)
{
    return nWays(0, s);
}

// DP - top down approach (recusive)
int nWays(int idx, string s, vector<int> &dp)
{
    int n = s.size();
    if (idx == n)
    {
        return 1;
    }
    else if (s[idx] == '0')
    {
        return 0;
    }
    else if (dp[idx] != -1)
    {
        return dp[idx];
    }
    if ((idx < n - 1) && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] < '7')))
    {
        return dp[idx] = nWays(idx + 1, s, dp) + nWays(idx + 2, s, dp);
    }
    return dp[idx] = nWays(idx + 1, s, dp);
}

int numDecodings(string s)
{
    vector<int> dp(s.size(), -1);
    return nWays(0, s, dp);
}

// DP - bottom up approach (iterative)

int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            if ((i < n - 1) && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }
    }
    return s.empty() ? 0 : dp[0];
}
