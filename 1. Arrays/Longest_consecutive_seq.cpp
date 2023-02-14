#include <bits/stdc++.h>
using namespace std;

// Approach1 - Sorting and counting
int longestCons1(vector<int> nums)
{
    int maxAns = 0, count = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] + 1 == nums[i + 1])
        {
            count++;
            maxAns = max(count, maxAns);
        }
        else
        {
            count = 1;
        }
    }
    return maxAns;
}

// Approach2 - Using hashset
int longestCons2(vector<int> nums)
{
    int maxAns = 0;
    unordered_set<int> uns;
    for (int i = 0; i < nums.size(); i++)
    {
        uns.insert(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!uns.count(nums[i] - 1))
        {
            int currNum = nums[i];
            int count = 1;
            while (uns.count(currNum + 1))
            {
                count++;
                currNum++;
            }
            maxAns = max(count, maxAns);
        }
    }
    return maxAns;
}

int main()
{
    vector<int> arr{100, 200, 1, 2, 3, 4};

    // cout << longestCons1(arr);
    cout << longestCons2(arr);

    return 0;
}