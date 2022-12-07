#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    int countPrime = 0;
    prime[0] = prime[1] = false;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            countPrime++;
            for (int i = p * p; i <= n; i = i + p)
            {
                prime[i] = false;
            }
        }
    }
    for (int p = 0; p <= n; p++)
    {
        if (prime[p])
        {
            cout << p << " ";
        }
    }
}

int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
