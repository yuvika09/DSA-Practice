// we will make two parts of the array sorted and unsorted

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    insertionSort(arr, size);
    return 0;
}