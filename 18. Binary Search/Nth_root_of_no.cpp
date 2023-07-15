#include <bits/stdc++.h>
#define ll long long
using namespace std;

// For integer values only

int NthRoot1(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// For Decimal values also(answer in all cases)

double mult(double mid, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

double NthRoot(int n, int m)
{
    double low = 1, high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = low + (low - high) / 2.0;
        if (mult(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return low;
}