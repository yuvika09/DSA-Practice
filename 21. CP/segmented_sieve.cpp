#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int N = 1000000;
vector<bool> sieve(N + 1, true);

void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j++)
            {
                sieve[j] = false;
            }
        }
    }
}

vector<int> generatePrimes(int N)
{
    vector<int> ds;
    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            ds.push_back(i);
        }
    }
    return ds;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    createSieve();

    // generate all primes
    vector<int> primes = generatePrimes(sqrt(r));

    // create a dummy array
    vector<bool> dummy(r - l + 1, true);

    // mark all the multiples in dummy
    for (auto i : primes)
    {
        int firstMultiple = (l / i) * i;
        if (firstMultiple < l)
        {
            firstMultiple += i;
        }
        for (int j = max(firstMultiple, i * i); j <= r; j = j + i)
        {
            dummy[j - l] = false;
        }
    }

    //get all primes
    for (int i = l; i <= r; i++)
    {
        if (dummy[i - l])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int q = 1;
    cin >> q;
    while (q--)
    {
        solve();
        cout << endl;
    }
    return 0;
}