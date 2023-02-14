// Searching of an element in a sorted and rotated array
// An optimized version of binary search is used.

#include <bits/stdc++.h>
using namespace std;

int search(int a[], int s, int key)
{
    int l = 0, r = s - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > a[l])
        {
            if (key >= a[l] && key < a[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (key >= a[mid] && key < a[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[7] = {120, 130, 40, 50, 90, 100, 110};
    cout << search(arr, 7, 90) + 1;
    return 0;
}