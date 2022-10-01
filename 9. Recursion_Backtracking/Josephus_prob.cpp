// There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds
// around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The
// elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last
// person remains, who is given freedom.

#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }
    else
    {
        return ((josephus(n - 1, k) + k) % n);
    }
}

int main()
{
    int n = 5, k = 3;
    cout << josephus(n, k) << endl;
    return 0;
}