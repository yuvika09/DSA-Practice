// return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int maxMoney(int n, vector<int> arr)
{
    int prev = arr[0];
    int prev2 = 0, curr;
    for (int i = 1; i <= n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += prev2;
        }
        int notPick = 0 + prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            temp1.push_back(nums[i]);
        }
        if (i != n - 1)
        {
            temp2.push_back(nums[i]);
        }
    }
    return max(maxMoney(n - 2, temp1), maxMoney(n - 2, temp2));
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    cout << rob(arr);
    return 0;
}