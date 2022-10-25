#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve()
{
    int a, ans = 0;
    map<int, int> m;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
    }
    ans = m[4] + m[3] + ceil((float)(m[2]) / 2.0);
    if (m[1] > m[3])
    {
        m[1] -= m[3];
    }
    else
    {
        m[1] = 0;
    }
    if (m[2] % 2 == 1 && m[1] > 0)
    {
        m[1] -= 2;
    }
    if (m[1] > 0)
    {
        ans += ceil((float)(m[1]) / 4.0);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int q = 1;
    // cin >> q;
    while (q--)
    {
        solve();
        cout << endl;
    }
    return 0;
}