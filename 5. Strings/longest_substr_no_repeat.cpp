// Given a string s, find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

// Approach1 -
int lengthSubstr(string s)
{
    int n = s.length();
    unordered_set<int> us;
    int l = 0;
    int maxLen = 0;
    for (int r = 0; r < n; r++)
    {
        if (us.find(s[r]) != us.end())
        {
            while (us.find(s[r]) != us.end() && l < r)
            {
                us.erase(s[l]);
                l++;
            }
        }
        us.insert(s[r]);
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// Approach2 -
int lengthSubstr2(string s)
{
    int n = s.length();
    unordered_map<int, int> um;
    int l = 0, maxLen = 0;
    for (int r = 0; r < n; r++)
    {
        if (um.find(s[r]) != um.end()  && l < r)
        {
            l = max(um[s[l]] + 1, l);
        }
        um[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

// int lengthofLongestSubstring(string s)
// {
//     vector<int> mpp(256, -1);
//     int left = 0, right = 0;
//     int n = s.size();
//     int len = 0;
//     while (right < n)
//     {
//         if (mpp[s[right]] != -1)
//             left = max(mpp[s[right]] + 1, left);
//         mpp[s[right]] = right;
//         len = max(len, right - left + 1);
//         right++;
//     }
//     return len;
// }

int main()
{
    string s = "abcaabcdba";
    cout << lengthSubstr2(s);

    return 0;
}