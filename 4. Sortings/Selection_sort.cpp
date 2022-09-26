// Put the smallest element from the unsorted array in the end of the sorted array

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
// Swap the found minimum element with the first element
            swap(arr[minIdx], arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {8, 3, 5, 2, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    return 0;
}