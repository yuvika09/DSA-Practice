#include <bits/stdc++.h>
using namespace std;

void sumSubset(set<int> &s, vector<int> &a, int idx, int sum)
{
    if (idx == a.size())
    {
        s.insert(sum);
        return;
    }
    sumSubset(s, a, idx + 1, sum + a[idx]);
    sumSubset(s, a, idx + 1, sum);
}

int main()
{
    vector<int> a{5,2,1};
    int sum = 0, idx = 0;
    set<int> s;
    sumSubset(s, a, idx, sum);
    for (auto i : s)
    {
        cout << i << " ";
    }
    return 0;
}