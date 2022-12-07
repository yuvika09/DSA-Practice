//if the letter number is single-digit number (less than 10), then just writes it out;
//if the letter number is a two-digit number (greater than or equal to 10), then it writes it out and adds the number 0 after.

// if the string s is code
// Thus, code of string code is 315045.

// You are given a string t resulting from encoding the string s. Your task is to decode it

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a;
        cin >> a;
        string s;
        cin >> s;
        string ans = "";
        for (int i = a - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                string num = "";
                num = num + s[i - 2] + s[i - 1];
                int n = stoi(num);
                ans += n + 'a' - 1;
                i -= 2;
            }
            else
            {
                ans += s[i] - '0' + 'a' - 1;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}