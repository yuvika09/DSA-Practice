#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int st = 0, last = n - 1;
    while (last >= st)
    {
        swap(s[st++], s[last--]);
    }
    cout << s;
    return 0;
}