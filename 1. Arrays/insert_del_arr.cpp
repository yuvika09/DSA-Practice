#include <bits/stdc++.h>
using namespace std;

int *insert(int arr[], int num, int pos, int size)
{
    for (int i = size; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = num;
    return arr;
}

int *del(int arr[], int pos, int size)
{
    for (int i = pos - 1; i <= size; i++)
        arr[i] = arr[i + 1];
    return arr;
}

int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    int num, pos;
    cin >> num >> pos;
    insert(arr, num, pos, a);
    for (int i = 0; i < a + 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    del(arr, 3, a);
    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}