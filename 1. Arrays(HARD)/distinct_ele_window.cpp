// Count distinct elements in every window of size k

#include <bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int K, int N)
{
    // Creates an empty hashmap m
    unordered_map<int, int> m;

    // initialize distinct element count for current window
    int count = 0;

    // Traverse the first window and store count
    // of every element in hash map
    for (int i = 0; i < K; i++)
    {
        if (m[arr[i]] == 0)
        {
            count++;
        }
        m[arr[i]]++;
    }
    // Print count of first window
    cout << count << endl;

    // Traverse through the remaining array
    for (int i = K; i < N; i++)
    {
        // Remove first element of previous window
        // If there was only one occurrence, then reduce distinct count.
        if (m[arr[i - K]] == 1)
        {
            count--;
        }
        // reduce count of the removed element
        m[arr[i - K]]--;

        // Add new element of current window
        // If this element appears first time,
        // increment distinct element count
        if (m[arr[i]] == 0)
        {
            count++;
        }
        m[arr[i]]++;

        // Print count of current window
        cout << count << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
    countDistinct(arr, K, N);
    return 0;
}
