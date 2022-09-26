// Finding largest sum of contigous subarray by
//  Brute force
// Kadane's Algorithm
// Kadane's Algorithm for all negative no.s also

#include <bits/stdc++.h>
#define ll long long
#define n 6
using namespace std;

ll bruteSum(int arr[])
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

// ll kadaneAlgo(int arr[]){
//     ll maxSum = 0, currSum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         currSum += arr[i];
//         maxSum = max(maxSum, currSum);
//         if(currSum < 0)
//             currSum = 0;
//     }
//     return maxSum;
// }

int kadaneAlgo(int arr[])
{
    int maxSum = INT_MIN, currSum = 0, maxEle = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;
        maxEle = max(maxSum, arr[i]);
    }
    return maxEle;
}

int main()
{
    int arr[] = {-5, 3, 6, 3, -4, 1};
    cout << kadaneAlgo(arr) << endl;
    return 0;
}