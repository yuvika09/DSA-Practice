#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

ll findAns(int r, int a)
{
    ll ans = 0;
    ans = (r / a) + (r % a);
    return ans;
}

void solve()
{
    int l, r, a;
    ll ans = 0;
    cin >> l >> r >> a;
    if (r % a == 0)
    {
        ans = findAns(r, a);
    }
    else
    {
        ans = findAns(r - 1, a);
    }
    cout << ans;
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