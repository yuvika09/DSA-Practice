#include <bits/stdc++.h>
using namespace std;

bool isPoss(vector<int> &piles, int sp, int h)
{
    int time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        time += ceil(piles[i] * 1.0 / sp);
    }
    return time <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int mx = INT_MIN, ans = 1;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, piles[i]);
    }
    if (h == n)
    {
        return mx;
    }

    int lo = 0, hi = mx;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPoss(piles, mid, h))
        {
            // ans = min(ans, mid);
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}