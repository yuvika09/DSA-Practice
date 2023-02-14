// find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

#include <bits/stdc++.h>
using namespace std;

void uniqueComb(vector<int> a, int target, vector<vector<int>> &ans, vector<int> &temp, int idx)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i > idx && a[i] == a[i - 1])
        //a-1 for 0 does not exist therefore order must be this only
        {
            continue;
        }
        if (a[i] > target)
        {
            break;
        }
        temp.push_back(a[i]);
        uniqueComb(a, target - a[i], ans, temp, i + 1);
        temp.pop_back();
    }
}

int main()
{
    vector<int> arr{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    uniqueComb(arr, target, ans, temp, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}