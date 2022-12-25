#include <bits/stdc++.h>
using namespace std;

//Approach1 - sorting
//Approach2 - countind 012

//Approach3 - 3 pointers
void sort012(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums{0,1,1,0,1,2,1,2,0,0,0,1};
    sort012(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}