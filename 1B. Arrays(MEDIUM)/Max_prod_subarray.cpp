#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;
    int left = 1, right = 1;

    // Can be also implemented in a single loop
    for (int i = 0; i < n; i++)
    {
        left = left * nums[i];
        maxi = max(maxi, left);
        if (left == 0)
        {
            left = 1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        right = right * nums[i];
        maxi = max(maxi, right);
        if (right == 0)
        {
            right = 1;
        }
    }
    return maxi;
}