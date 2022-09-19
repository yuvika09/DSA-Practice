// Given a matrix m x n
// find the number of ways in which we can go from
// leftmost top to rightmost bottom just by moving right and down


#include <bits/stdc++.h>
using namespace std;

int ways(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    else
    {
        return (ways(m - 1, n) + ways(m, n - 1));
    }
}

int main()
{
    int m = 3, n = 3;
    cout << ways(m, n) << endl;
    return 0;
}