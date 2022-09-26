//Buying and selling stocks such that maximum profit is obtained.
//Given array of the stock price per day. First buy a stock then only selling is possible.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Using array preprocessing O(N) time complexity and O(N) space complexity

int maxProfit1(int arr[], int size)
{
    int arr2[size];
    int maxEle = arr[size - 1];
    int maxProfit = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        maxEle = max(maxEle, arr[i]);
        arr2[i] = maxEle;
    }
    for (int i = 0; i < size; i++)
    {
        maxProfit = max(maxProfit, (arr2[i] - arr[i]));
    }
    return maxProfit;
}

// O(N) time complexity and O(1) space complexity

int maxProfit2(int arr[], int size)
{
    int minSoFar = arr[0];
    int maxProfit = 0;
    for (int i = 0; i < size; i++)
    {
        minSoFar = min(minSoFar, arr[i]);
        int Profit = arr[i] - minSoFar;
        maxProfit = max(maxProfit, Profit);
    }
    return maxProfit;
}

int main()
{
    int arr[] = {3, 1, 4, 8, 7, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit2(arr, n);
}