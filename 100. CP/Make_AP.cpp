
// Choose a positive integer m and multiply exactly one of the integers a, b or c by m.
// Can Polycarp make it so that after performing the operation, the sequence of three numbers a, b, c (in this order) forms an arithmetic progression

// (b-a) = (c-b)
// m*(2b) = (a+c)      a+c must be completely divisible by 2b
// m*(c) = (2b-a)>0
// m*(a) = (2b-c)>0

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int B = 2 * b;
    if (b - a == c - b)
    {
        cout << "YES";
    }
    else if ((a + c) % B == 0)
    {
        cout << "YES";
    }
    else if (((B - a) % c == 0) && (B - a) > 0)
    {
        cout << "YES";
    }
    else if (((B - c) % a == 0) && (B - c) > 0)
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