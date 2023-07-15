// There is a new barn with N stalls and C cows We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool canPlace(vector<int> &stalls, int k, int minDist)
{
    int n = stalls.size(), cows = 1;
    int lastCow = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if ((stalls[i] - lastCow) >= minDist)
        {
            cows++;
            lastCow = stalls[i];
        }
        if (cows == k)
        {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}