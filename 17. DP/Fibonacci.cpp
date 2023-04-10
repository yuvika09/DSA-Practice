#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int fiboMemo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp);
}

int fiboTab(int n, vector<int> &dp)
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fiboOptimized(int n)
{
    int prev2 = 0, prev = 1;
    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << fiboMemo(n, dp);
    cout << fiboTab(n, dp);
    cout << fiboOptimized(n);

    return 0;
}