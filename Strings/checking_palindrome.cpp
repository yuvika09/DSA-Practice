#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        string s2 = s;
        reverse(s.begin(), s.end());
        if (s == s2){
            cout << "PALINDROME";
            break;
        }
        
        // if (s[i] != s[n - i - 1]){
        //     cout << "NOT PALINDROME";
        //     break;
        // }
    }
}