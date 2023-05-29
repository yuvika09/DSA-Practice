// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> ans, string temp, int op, int cl)
{
    if (op == 0 && cl == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (op > 0)
    {
        temp.push_back('(');
        solve(ans, temp, op - 1, cl);
        temp.pop_back();
    }
    if (cl > op)
    {
        temp.push_back(')');
        solve(ans, temp, op, cl - 1);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string temp;
    int op = n, cl = n;
    solve(ans, temp, op, cl);
    return ans;
}