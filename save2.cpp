#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))

using namespace std;

void solve()
{
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] + i;
    }
    sort(a.begin(), a.end());
    int i = 0;
    while (i<n-1)
    {
        if (m - a[i] < 0)
        {
            break;
        }
        m -= a[i];
        i++;
        count++;
    }
    cout << count;
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