// Given two integers a and b, return the sum of the two integers without using the operators + and -.

#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b)
{
    while (b != 0)
    {
        unsigned int temp = a & b; // for identifying carry
        a ^= b;                    // for addition of 01, 10, 00
        b = temp << 1;             // shifting carry to left
    }
    return a;
}