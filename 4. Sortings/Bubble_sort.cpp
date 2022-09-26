// Compare 2 adjacent elements

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = 0; // decreases time(if already sorted no loops repeated)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
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
    bubbleSort(arr, size);
    return 0;
}