#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    int n, m, k, x, y;
    cin >> n >> m >> k;
    int a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    if (n % k == 0)
    {
        x = n / k;
        for (int i = 0; i < m; i++)
        {
            if (a[i] > x)
            {
                cout << "NO";
                return;
            }
        }
    }
    else
    {
        x = n / k;
        y = n % k;
        // cout << x << " " << y;
        int c = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[i] == x + 1)
            {
                c++;
            }
        }
        if (c != y)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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