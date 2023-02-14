#include <bits/stdc++.h>
using namespace std;

// always use sorted array

int binary_search_recursive(int arr[], int num, int lb, int ub)
{
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            // ub = mid-1;
            binary_search_recursive(arr, num, lb, mid - 1);
        else
            binary_search_recursive(arr, num, mid + 1, ub);
    }
    return -1;                // if we reach here then element is not present in the array
}
int binary_search_iterative(int arr[], int num, int lb, int ub)
{
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] > num)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return -1;                       // if we reach here then element is not present in the array
}

int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    int res = binary_search_recursive(arr, 7, 0, a - 1);
    if (res == -1)
        cout << "Element not found";
    else
        cout << "Element found at " << res + 1 << endl;
    return 0;
}