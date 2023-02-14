#include <bits/stdc++.h>
using namespace std;


//Approach3 - Using hashmapping
int maxLen0(int arr[], int n)
{
    unordered_map<int, int> m;
    int preSum = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (m.find(preSum) == m.end())
            {
                m[preSum] = i;
            }
            else
            {
                maxi = max(maxi, (i - m[preSum]));
            }
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {1, 2, -2, 4, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxLen0(arr, n);
    return 0;
}