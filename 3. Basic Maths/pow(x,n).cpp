#include <iostream>
#define ll long long
using namespace std;

double powMade(double x, int n)
{
    ll cpn = n;
    double ans = 1;
    if (n < 0)
    {
        cpn = (-1) * cpn;
    }
    while (cpn)
    {
        if (cpn % 2 == 0)
        {
            x *= x;
            cpn /= 2;
        }
        else
        {
            ans *= x;
            cpn--;
        }
    }
    if (n < 0)
    {
        ans = (double)1 / (double)ans;
    }
    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << powMade(x, n);
    return 0;
}