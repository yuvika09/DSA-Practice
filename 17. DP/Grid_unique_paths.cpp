#include <bits/stdc++.h>
using namespace std;

int recUniqueWays(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    else if (i >= n || j >= m)
    {
        return 0;
    }
    else
    {
        return recUniqueWays(i + 1, j, n, m) + recUniqueWays(i, j + 1, n, m);
    }
}

int dpUniqueWays(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = recUniqueWays(i + 1, j, n, m) + recUniqueWays(i, j + 1, n, m);
    return dp[i][j];
}

int combUniqueWays(int n, int m)
{
    int N = n + m - 2;
    int r = min(m, n) - 1;
    int res = 1;

    for (int i = 1; i <= r; i++)
    {
        res = (res * (N - r + i)) / i;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    // cout << recUniqueWays(0, 0, n, m);

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // cout << dpUniqueWays(0, 0, n, m, dp);

    cout << combUniqueWays(n, m);

    return 0;
}