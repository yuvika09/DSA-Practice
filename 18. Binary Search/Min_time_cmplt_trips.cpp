// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

// Input: time = [1,2,3], totalTrips = 5
//  Output: 3

#include <bits/stdc++.h>
using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
    sort(time.begin(), time.end());
    long long l = 0, r = 1e14;
    long long ans = 1e14;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long trips = 0;
        for (int i = 0; i < time.size(); i++)
        {
            trips += mid / time[i];
        }
        if (trips >= totalTrips)
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
