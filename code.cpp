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
    string s;
    cin >> s;
    map<char, int> mp1, mp2;
    mp1[s[0]]++;
    
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