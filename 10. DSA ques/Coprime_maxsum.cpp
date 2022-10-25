// Find the maximum value of i+j such that ai and aj are coprime, or −1 if no such i, j exist.
// For example consider the array [1,3,5,2,4,7,7]. 
//The maximum value of i+j that can be obtained is 5+7, since a5=4 and a7=7 are coprime.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)

using namespace std;

void solve()
{
    int a, ans = INT_MIN;
    cin >> a;
    int arr[a];
    for (int i = 1; i <= a; i++)
    {
        cin >> arr[i];
    }
    int maxIdx[1001] = {0};
    for (int i = 1; i <= a; i++)
    {
        maxIdx[arr[i]] = i;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            if (maxIdx[i] > 0 && maxIdx[j] > 0)
            {
                if (gcd(i, j) == 1)
                {
                    ans = max(ans, (maxIdx[i] + maxIdx[j]));
                }
            }
        }
    }
    if (ans == INT_MIN)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int q = 1;
    cin >> q;
    while (q--)
    {
        solve();
        cout << endl;
    }
    return 0;
}