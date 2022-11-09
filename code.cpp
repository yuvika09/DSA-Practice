#include <bits/stdc++.h>
#define ll long long
using namespace std;

void primeFactors(ll n, set<int> &s)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        s.insert(n);
    }
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    bool fl = 1;
    set<int> s;
    primeFactors(b, s);
    for (auto i : s)
    {
        if (a % i != 0)
        {
            fl = 0;
        }
        // cout << i << " ";
    }
    if (fl == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
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