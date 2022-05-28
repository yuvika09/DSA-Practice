#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    char c;
    int n = s.size();
    int hash[26] = {0};
    for (int i = 0; i < n; i++)
        hash[s[i] - 97]++;
    for (int i = 0; i < 26; i++)
    {
        if(hash[i]>1){
            c = i+97;
            cout << c << " ";
            cout << hash[i] << endl;
        }
    }
    return 0;
}