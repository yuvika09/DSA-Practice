#include <bits/stdc++.h>
using namespace std;

vector<int> minCoins(int coins[], int v, int n)
{
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (v >= coins[i])
        {
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}

int main()
{
    int v = 121;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);
    vector<int> ans = minCoins(coins, v, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}