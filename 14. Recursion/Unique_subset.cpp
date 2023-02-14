// MEDIUM
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>
using namespace std;

void uniqueSubset(vector<vector<int>> &ans, vector<int> &ds, vector<int> a, int idx)
{
    ans.push_back(ds);
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[i - 1])
        {
            continue;
        }
        ds.push_back(a[i]);
        uniqueSubset(ans, ds, a, i + 1);
        ds.pop_back();
    }
}

int main()
{
    vector<int> a{1, 2, 2, 2, 3, 3};
    vector<vector<int>> ans;
    vector<int> ds;
    sort(a.begin(), a.end());
    uniqueSubset(ans, ds, a, 0);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)//size chngs
        {
            cout << ans[i][j];
        }
        cout << "] ";
    }
    cout << "] ";
    return 0;
}