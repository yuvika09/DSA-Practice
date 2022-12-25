#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    if (nums.empty())
    {
        return ans;
    }
    int s = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            ll newTar = (ll)target - (nums[i] + nums[j]);

            int left = j + 1, right = s - 1;
            while (left < right)
            {
                ll twoSum = nums[left] + nums[right];
                if (twoSum < newTar)
                {
                    left++;
                }
                else if (twoSum > newTar)
                {
                    right--;
                }
                else
                {
                    vector<int> quad(4);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    ans.push_back(quad);

                    while (left < right && nums[left] == quad[2])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == quad[3])
                    {
                        right--;
                    }
                }
            }
            while ((j + 1) < s && nums[j + 1] == nums[j])
            {
                j++;
            }
        }
        while ((i + 1) < s && nums[i + 1] == nums[i])
        {
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int>> ans = fourSum(nums, -294967296);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}