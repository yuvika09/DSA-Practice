#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    char c;
    int n = s.size();
    long int h = 0;   //variable to set each character's bit
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = 1;     //start from least significant bit
        x = x << (s[i] - 97);    //leftshift by this no. of times
        if ((x & h) > 0) 
        {
            cout << s[i] << " "; //if set before -- then duplicate present
        }
        else    
            h = x|h;    // it not set before -- set now
    }
    return 0;
}
