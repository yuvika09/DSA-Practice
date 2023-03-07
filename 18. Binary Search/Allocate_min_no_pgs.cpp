#include <bits/stdc++.h>
using namespace std;
 
bool isPossible(int A[], int mid, int N, int M)
{
    int st = 1, sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum > mid)
        {
            st++;
            sum = A[i];
        }
    }
    if (st <= M)
    {
        return true;
    }
    return false;
}

int findPages(int A[], int N, int M)
{
    if (N < M)
    {
        return -1;
    }
    int sum = 0, maxi = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        maxi = max(A[i], maxi);
    }

    int low = maxi, high = sum;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(A, mid, N, M))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        return ans;
    }
}
