#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b / gcd(a, b))

using namespace std;

vector<int> reverse(vector<int> arr, int n)
{
    int st = arr[0], end = arr[n - 1];
    while (st < end)
    {
        int temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++; end--;
    }
    return arr;
}