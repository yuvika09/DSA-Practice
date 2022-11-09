// You are given an array a of n integers. Count the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.
// now j-aj == i-ai
// use map to keep freq of this data
// now if freq is 1 don't add to res otherwise with each increment in the value add to the res
// here we are taking sum of new freq each time to get all the combinations of pair

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> m;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        a = i - a;
        ans += m[a];
        m[a]++;
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