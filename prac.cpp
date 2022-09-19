#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        ll arr[n];
        map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]]++;
        }
        for (auto i : m)
        {
            // cout << i.first << " " << i.second << endl;
            if (i.second > 1)
            {
                ans += (i.second * (i.second - 1)) / 2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}