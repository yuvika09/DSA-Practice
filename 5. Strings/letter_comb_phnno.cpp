#include <bits/stdc++.h>
using namespace std;

// Letter Combinations of a Phone Number

class Solution
{
private:
    void backtrack(vector<string> &ans, vector<string> &mp, string &temp, string &digits, int idx)
    {
        if (idx == digits.size())
        {
            ans.push_back(temp);
        }
        else
        {
            string letters = mp[digits[idx] - '0'];
            for (char it : letters)
            {
                temp[idx] = it;
                backtrack(ans, mp, temp, digits, idx + 1);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.empty())
        {
            return ans;
        }
        vector<string> mp = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"};
        string temp(digits.size(), ' ');
        backtrack(ans, mp, temp, digits, 0);
        return ans;
    }
};