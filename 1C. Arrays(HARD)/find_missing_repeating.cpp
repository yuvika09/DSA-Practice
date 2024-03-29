// Find the missing and repeating number in the given array

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// APPROACH 1 - hashing O(N), O(N)
void findMissingRepeating1(vector<int> &nums)
{
    int miss = 0, rep = 0;
    int hash[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        if (hash[i] == 0)
        {
            miss = i;
        }
        if (hash[i] > 1)
        {
            rep = i;
        }
    }
    cout << miss << " " << rep;
}

// APPROACH 2 - Using maths
vector<int> repeatedNumber(const vector<int> &arr)
{
    int x, y;
    int n = arr.size();
    ll sum = 0, sqSum = 0;
    sum = (n * (n + 1)) / 2;
    sqSum = (n * (n + 1) * ((2 * n) + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        sum -= (ll)arr[i];
        sqSum -= ((ll)arr[i] * (ll)arr[i]);
    }

    x = (sqSum - (sum * sum)) / (2 * sum);
    y = sum + x;
    return {x, y};
}

// APPROACH 3 - XOR
vector<int> repeatedNumber(const vector<int> &arr)
{
    /* Will hold xor of all elements and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers from 1 to n */
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two sets by comparing a rightmost set bit
       of xor1 with the bit at the same position in each element.
       Also, get XORs of two sets. The two XORs are the output elements.
       The following two for loops serve the purpose */

    for (i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            x = x ^ arr[i];

        else
            /* arr[i] belongs to second set */
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            /* i belongs to first set */
            x = x ^ i;

        else
            /* i belongs to second set */
            y = y ^ i;
    }

    // NB! numbers can be swapped, maybe do a check ?
    int x_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            x_count++;
    }

    if (x_count == 0)
        return {y, x};

    return {x, y};
}

int main()
{
    vector<int> nums{4, 3, 6, 2, 1, 1};
    findMissingRepeating1(nums);
    return 0;
}