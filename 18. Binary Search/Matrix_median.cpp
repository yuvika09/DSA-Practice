#include <bits/stdc++.h>
using namespace std;

int smallThanMid(vector<int> &row, int mid)
{
    int lo = 0, hi = row.size() - 1;
    while (lo <= hi)
    {
        int md = lo + (hi - lo) / 2;
        if (row[md] <= mid)
        {
            lo = md + 1;
        }
        else
        {
            hi = md - 1;
        }
    }
    return lo;
}

int findMedian(vector<vector<int>> &mat)
{
    int low = 1, high = 1e9;
    int n = mat.size(), m = mat[0].size();
    int total = n * m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += smallThanMid(mat[i], mid);
        }
        if (count <= (total / 2))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}