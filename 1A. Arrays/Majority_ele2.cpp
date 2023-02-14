// Boyer Moore's Voting Algorithm
// Find all elements that appear more than ⌊ n/3 ⌋ times.

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    vector<int> ans;
    int num1 = -1, c1 = 0, num2 = -1, c2 = 0;
    for (auto i : nums)
    {
        if (i == num1)
            c1++;
        else if (i == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = i;
            c1++;
        }
        else if (c2 == 0)
        {
            num2 = i;
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    // cout << num1 << num2 << "H";
    c1 = c2 = 0;
    for (auto i : nums)
    {
        if (i == num1)
            c1++;
        else if (i == num2)
            c2++;
    }
    int s = nums.size();
    if (c1 > (s / 3))
        ans.push_back(num1);
    if (c2 > (s / 3))
        ans.push_back(num2);
    return ans;
}

int main()
{
    vector<int> v{1, 1, 1, 2, 2, 3, 3, 3};
    vector<int> maj = majorityElement(v);
    for (auto i : maj)
    {
        cout << i << " ";
    }
    return 0;
}