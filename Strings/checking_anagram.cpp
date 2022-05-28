// two strings are anagram when both have same alpabets used in the string

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int hash1[26] = {0};
    int hash2[26] = {0};
    int fl = 1, n = s1.size();
    for (int i = 0; i < n; i++)
        hash1[s1[i] - 97]++;
    for (int i = 0; i < n; i++)
        hash2[s2[i] - 97]++;

    for (int i = 0; i < 26; i++)
    {
        if (hash1[i] != hash2[i])
        {
            fl = 0;
            break;
        }
    }
    if (fl == 1)
        cout << "ANAGRAM" << endl;
    else
        cout << "NOT ANAGRAM" << endl;
    return 0;
}