// You are given an integer array nums and two integers minK and maxK.
//  A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
//  The minimum value in the subarray is equal to minK.
//  The maximum value in the subarray is equal to maxK.
//  Return the number of fixed-bound subarrays.

// Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
// Output: 2
// Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll countSubarrays(vector<int> &nums, int minK, int maxK)
{
    // initialize some variables
    int n = nums.size();
    int leftBound = -1;
    int lastMin = -1, lastMax = -1;
    ll count = 0;

    for (int i = 0; i < n; i++)
    {
        // check if nums[i] is within the range [minK, maxK]
        if (nums[i] >= minK && nums[i] <= maxK)
        {
            // if nums[i] is equal to minK, update lastMin to the current index i
            lastMin = (nums[i] == minK) ? i : lastMin;
            // if nums[i] is equal to maxK, update lastMax to the current index i
            lastMax = (nums[i] == maxK) ? i : lastMax;
            // update the count by the number of valid subarrays between leftBound and the
            // smaller of lastMin and lastMax
            count += max(0, min(lastMin, lastMax) - leftBound);
        }
        else
        {
            // if nums[i] is not within the range [minK, maxK], update leftBound to i
            leftBound = i;
            // reset lastMin and lastMax to -1
            lastMin = -1;
            lastMax = -1;
        }
    }
    // return the final count of valid subarrays
    return count;
}

// INTUTION
// This solution works by iterating over the given array nums and keeping track of the most recent positions of the minimum value minK and the maximum value maxK in the array, as well as the most recent index leftBound outside the range [minK, maxK].
//  For each element in the array, if it falls within the range [minK, maxK], the code updates the most recent positions of minK and maxK, calculates the number of subarrays that can be formed between the most recent positions of minK and maxK, and adds this count to the answer
//  If the current element falls outside the range [minK, maxK], the code updates the leftBound index to the current index i, and resets the most recent positions of minK and maxK to -1.
//  In the end, the code returns the total count of valid subarrays.