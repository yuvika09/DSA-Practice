// Reverse bits of a given 32 bits unsigned integer.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int lsb = n & 1; //get the lsb of n
        int revLsb = lsb << (31 - i); // take to its pos in rev no
        ans = ans | revLsb;
        n = n >> 1;
    }
    return ans;
}