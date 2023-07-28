#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

// APPROACH 1 - Brute Force

// APPROACH 2 - Using hashset
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hash;
        for (int j = i + 1; j < n; j++)
        {
            int k = (-1) * (nums[i] + nums[j]);
            if (hash.find(k) != hash.end()) // element found
            {
                vector<int> temp = {nums[i], nums[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// APPROACH 3 - Using 2 Pointer approach
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue; // no further steps of this iteration executed
        }
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1]){
                    k--;
                }
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}