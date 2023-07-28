// Find if there is a pair with a given sum in the rotated sorted Array

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool pairInSortedRotated(int *arr, int n, int sum)
{
    int pivot = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            pivot = i + 1;
            break;
        }
    }
    
    int left = pivot, right = pivot - 1;
    while (left != right)
    {
        if (arr[left] + arr[right] == sum)
        {
            return true;
        }
        else if (arr[left] + arr[right] < sum)
        {
            left = (left + 1) % n;
        }
        else
        {
            right = (right - 1 + n) % n;
        }
    }
    return false;
}