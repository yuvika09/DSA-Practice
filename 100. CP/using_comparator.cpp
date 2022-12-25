#include <bits/stdc++.h>
using namespace std;

// arranging first acc to descending order and second by also descending
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

void solve()
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end(), cmp);
    for (auto i : vp)
    {
        cout << i.first << " " << i.second << endl;
    }
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