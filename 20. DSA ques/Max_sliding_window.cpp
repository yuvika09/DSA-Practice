// Sliding window maximum using DEQUE(Doubly ended queue)

#include <bits/stdc++.h>
using namespace std;

//TLE for some cases
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

void printKMax(int arr[], int n, int k)
{
    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        while (!q.empty() && arr[q.front()] < arr[i])
            q.pop_front();

        q.push_front(i);

        if (i + 1 >= k)
        {
            cout << arr[q.back()];
            if (i + 1 == n)
                cout << "\n";
            else
                cout << " ";

            if (q.back() == i + 1 - k)
                q.pop_back();
        }
    }
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    printMax(arr, 8, 3);
    return 0;
}