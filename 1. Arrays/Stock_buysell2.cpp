// Buying and selling stocks such that maximum profit is obtained.
// Given array of the stock price per day.
//  Multiple stocks can be bought but not at the same time.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maxProfit(int arr[], int size)
{
    int profit = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main()
{
    int arr[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProfit(arr, n);
}