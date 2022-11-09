#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    if (mp.size() == n)
        return 0;
    int r, q;
    bool pp = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                r = j + 1;
                q = arr[j];
                pp = true;
                break;
            }
        }
        if (pp == true)
            break;
    }
    int ccc = 0;
    for (int p = r; p < n; p++)
    {
        if (arr[p] != q)
            ccc++;
    }
    if (ccc <= 2)
        return 1;
    else
        return 0;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {

        int aaa = solve();
        if (aaa == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
