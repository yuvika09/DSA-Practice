#include <bits/stdc++.h>
#define ll long long
using namespace std;

void subArrSum(int a[], int sum, int n)
{
    int currSum, start, end;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum - sum == 0)
        {
            start = 0;
            end = i;
            break;
        }
        if (m.find(currSum - sum) != m.end())
        {
            start = m[currSum - sum] + 1;
            end = i;
            break;
        }
        m[currSum] = i;
    }
    if (end == -1)
    {
        cout << " Not Found" << endl;
    }
    else
    {
        cout << start << " " << end << endl;
    }
}

int main()
{
    int arr[] = {10, 15, -5, 15, -10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    subArrSum(arr, 5, 7);
    return 0;
}