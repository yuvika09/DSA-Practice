#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    vector<int> leftProd(n), rightProd(n);
    leftProd[0] = 1;
    for (int i = 1; i < n; i++)
    {
        leftProd[i] = leftProd[i - 1] * nums[i - 1];
    }
    rightProd[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        rightProd[i] = rightProd[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = leftProd[i] * rightProd[i];
    }
    return ans;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> leftProd(n);
    leftProd[0] = 1;
    for (int i = 1; i < n; i++)
    {
        leftProd[i] = leftProd[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        leftProd[i] *= right;
        right *= nums[i];
    }
    return leftProd;
}