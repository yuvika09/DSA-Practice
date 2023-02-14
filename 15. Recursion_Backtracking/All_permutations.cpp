#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 - Recursion with some extra space

void permute1(vector<int> nums, vector<vector<int>> &ans, vector<int> &ds, bool hash[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash[i] == 0)
        {
            ds.push_back(nums[i]);
            hash[i] = 1;
            permute1(nums, ans, ds, hash);
            hash[i] = 0;
            ds.pop_back();
        }
    }
}

// APPROACH 2 - Recursion without extra space

void permute2(int idx, vector<int> nums, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        permute2(idx+1, nums, ans);
        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int> nums{1, 2, 3};

    vector<vector<int>> ans;
    vector<int> ds;
    bool hash[nums.size()] = {0};

    // permute1(nums, ans, ds, hash);
    permute2(0, nums, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}