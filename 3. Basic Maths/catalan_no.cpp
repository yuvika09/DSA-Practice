#include <iostream>
#define ull unsigned long long
using namespace std;

unsigned long int catalan1(ull n)
{
    if (n <= 1)
    {
        return 1;
    }
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan1(i) * catalan1(n - i - 1);
    }
    return res;
}

ull fact(ull n)
{
    if (n == 0)
    {
        return 1;
    }
    ull res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}

ull binomialCoeff(ull n, ull r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// A Binomial coefficient based function to find nth catalan number in O(n) time
ull catalan(ull n)
{
    ull c = binomialCoeff(2 * n, n);
    return c / (n + 1);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << catalan1(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << " ";
    }

    return 0;
}
