// Sliding window maximum using DEQUE(Doubly ended queue)

#include <bits/stdc++.h>
using namespace std;

void printMax(int arr[], int n, int k)
{
    deque<int> dq;
    // process first k(first window) elements of array
    for (int i = 0; i < k; i++)
    {
        // for every element prev element is useless so remove from dq
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // process rest of the elements k to n-1
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        // remove all elements smaller than the currently being added element
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " ";
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    printMax(arr, 8, 3);
    return 0;
}