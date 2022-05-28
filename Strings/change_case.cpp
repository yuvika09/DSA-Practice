#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int s = n.size();
    for (int i = 0; i < s; i++)
    {
        if(n[i] >= 'a' && n[i] <= 'z')
            n[i] -= 32;
        else if(n[i] >= 'A' && n[i] <= 'Z')
            n[i] += 32;
    }
    cout << n;

    return 0;
}