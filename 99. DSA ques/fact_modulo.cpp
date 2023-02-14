// Given a permutation p of n numbers, we create an array a consisting of 2n numbers, which is equal to p concatenated with its reverse. We then define the beauty of p as the number of inversions in a.
//  The number of inversions in the array a is the number of pairs of indices i, j such that i<j and ai>aj.
//  For example, for permutation p=[1,2], a would be [1,2,2,1]. The inversions in a are (2,4) and (3,4) (assuming 1-based indexing). Hence, the beauty of p is 2.Your task is to find the sum of beauties of all n! permutations of size n. Print the remainder we get when dividing this value by 1000000007(10^9+7).

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

// ll factorial(ll n)
// {
//     ll f = 1;
//     for (int i = 1; i <= n; i++)
//         f = (f * i) % M;
//     return f;
// }

ll factorial(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    return ((n)*factorial(n - 1)) % M;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    if (n == 1)
    {
        ans = 0;
    }
    else if (n == 2)
    {
        ans = 4;
    }
    else if (n > 2)
    {
        ans = ((factorial(n) % M) * ((n * (n - 1)) % M)) % M;
    }
    cout << ans;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
        cout << endl;
    }
    return 0;
}