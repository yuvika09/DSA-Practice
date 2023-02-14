// Using Moore's Voting Algorithm to find majority element in the array
// The majority element is the element that appears more than ⌊n / 2⌋ times.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int count = 0, ele = 0;
    for (int i : nums)
    {
        if (count == 0)
        {
            ele = i;
        }
        if (i == ele)
            count += 1;
        else
            count -= 1;
    }
    return ele;
}

int main()
{
    vector<int> arr{5, 1, 4, 1, 1};
    cout << majorityElement(arr);
    return 0;
}