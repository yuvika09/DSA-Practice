#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int st, int end)
{
    while (st <= end)
    {
        if (s[st++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void stringPartition(string s, vector<vector<string>> &ans, vector<string> &temp, int idx)
{
    if (idx == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPal(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            stringPartition(s, ans, temp, i + 1);
            temp.pop_back();
        }
    }
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> ans;
    vector<string> temp;
    stringPartition(s, ans, temp, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}