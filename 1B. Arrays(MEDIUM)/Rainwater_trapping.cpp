//Given an array of N non-negative integers arr[] representing an elevation map where the width of each bar
// is 1, compute how much water it is able to trap after raining.
//Array PREPROCESSING used

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll waterTrapped(int arr[], int n)
{
    int left[n], right[n];
    ll sum = 0;
    left[0] = arr[0];
    right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }
    for (int i = 0; i < n; i++)
    {
        sum += min(left[i], right[i]) - arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << waterTrapped(arr, size) << endl;
    return 0;
}