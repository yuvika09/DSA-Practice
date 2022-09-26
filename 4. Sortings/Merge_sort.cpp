// breaks array into one element and then sort them while merging

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int k = 0;
    int b[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (j <= r)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }

    for (int i = l; i <= r; i++)
        arr[i] = b[i-l];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {8, 3, 5, 2, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}