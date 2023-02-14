#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    string ans = "";
    k--;
    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + (k / fact));
        if (nums.size() == 0)
        {
            break;
        }
        k %= fact;
        fact /= nums.size();
    }
    return ans;
}

int main()
{
    int n = 4, k = 17;
    string s = kthPermutation(n, k);
    cout << s;
    return 0;
}