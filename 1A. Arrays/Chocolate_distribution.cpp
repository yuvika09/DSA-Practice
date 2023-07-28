// Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:
//  Each student gets one packet.
//  The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
// m is number of students.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))

using namespace std;

int findMinDiff(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    sort(arr, arr + n);
    if (n < m)
    {
        return -1;
    }
    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        minDiff = min(diff, minDiff);
    }
    return minDiff;
}