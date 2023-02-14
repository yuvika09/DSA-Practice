// Get the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.The same number may be chosen from the given array an unlimited number of times.Two combinations are unique if the frequency of at least one of the chosen numbers is different.

#include <bits/stdc++.h>
using namespace std;

void uniqueComb(vector<int> a, int target, vector<vector<int>> &ans, vector<int> &temp, int idx)
{
    if (idx == a.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if (a[idx] <= target)
    {
        temp.push_back(a[idx]);
        uniqueComb(a, target - a[idx], ans, temp, idx);
        temp.pop_back();
    }
    uniqueComb(a, target, ans, temp, idx+1);
}

int main()
{
    vector<int> arr{2, 3, 6, 7};
    int target = 7;
    vector<int> temp;
    vector<vector<int>> ans;
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