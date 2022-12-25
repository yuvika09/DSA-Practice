#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Approach 1 - Brute Force
vector<int> twoSum1(vector<int> &nums, int target)
{
    int s = nums.size();
    vector<int> ans;
    for (int i = 0; i < s; i++)
    {
        int diff = target - nums[i];
        for (int j = i + 1; j < s; j++)
        {
            if (nums[j] == diff)
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

// Approach 2 - Hash mapping
vector<int> twoSum2(vector<int> &nums, int target)
{
    int s = nums.size();
    vector<int> ans;
    map<int, int> m;
    for (int i = 0; i < s; i++)
    {
        int diff = target - nums[i];
        if (m.find(diff) == m.end())
        {
            m[nums[i]] = i;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(m[diff]);
        }
    }
    return ans;
}

int main()
{
    vector<int> v{2, 7, 11, 15};
    vector<int> ans = twoSum2(v, 9);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}