#include <bits/stdc++.h>
using namespace std;

int *insert(int arr[], int num, int size)
{
    int i = size - 1;
    while (i > 0 && arr[i] > num)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = num;
    return arr;
}

int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    insert(arr, num, a);
    for (int i = 0; i < a + 1; i++)
        cout << arr[i] << " ";
    return 0;
}