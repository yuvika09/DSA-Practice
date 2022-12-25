// Finding largest sum of contigous subarray by
//  Brute force
// Kadane's Algorithm
// Kadane's Algorithm for all negative no.s also

#include <bits/stdc++.h>
#define ll long long
#define n 8
using namespace std;

ll bruteSum(int arr[])
{
    ll maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                maxSum = max(maxSum, sum);
            }
        }
    }
    return maxSum;
}

ll optimizedSum(int arr[])
{
    ll maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// int kadaneAlgo(int arr[])
// {
//     int maxSum = INT_MIN, currSum = 0, maxEle = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         currSum += arr[i];
//         maxSum = max(maxSum, currSum);
//         if (currSum < 0)
//             currSum = 0;
//         maxEle = max(maxSum, arr[i]);
//     }
//     return maxEle;
// }

int kadaneAlgo(int arr[])
{
    int maxSum = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << bruteSum(arr) << endl;
    // cout << kadaneAlgo(arr) << endl;
    
    return 0;
}