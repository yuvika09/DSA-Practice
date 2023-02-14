#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n, int k)
{
    int i = 0, j = 1;
    set<int> set;
    set.insert(arr[0]);
    int sum = arr[0];
    int maxsum = sum;

    while (i < n - 1 && j < n)
    {
        const bool is_in = set.find(arr[j]) != set.end();
        if (!is_in)
        {
            sum = sum + arr[j];
            if (j - i + 1 == k)
            {
                cout << (j - i) << "KK";
                maxsum = max(sum, maxsum);
            }
            set.insert(arr[j++]);
        }
        else
        {
            sum -= arr[i];
            set.erase(arr[i++]);
        }
    }
    
    return maxsum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            arr[i]--;
        }
    }
    int ans = maxSumSubarray(arr, n, k);
    cout << (ans);
}
