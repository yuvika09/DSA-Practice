#include <bits/stdc++.h>
using namespace std;

int countPlatforms(int arr[], int dep[], int n)
{
    int maxi = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        int count = 1;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        maxi = max(maxi, count);
    }
    return maxi;
}

int minPlatforms(int arr[], int dept[], int n)
{
    sort(arr, arr + n);
    sort(dept, dept + n);
    int i = 1, j = 0;
    int maxi = 0, count = 1;

    while (i < n && j < n)
    {
        if (arr[i] <= dept[j])
        {
            i++;
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            j++;
            count--;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {120, 50, 550, 200, 700, 850};
    int dept[] = {500, 550, 600, 700, 900, 1000};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << countPlatforms(arr, dept, size);
    cout << minPlatforms(arr, dept, size) << endl;
    return 0;
}