//Connect n ropes with minimum cost
//we need to find 2 min elements after one iteration(connection of 2 ropes)

#include <bits/stdc++.h>
using namespace std;

int minCost(int a[], int size)
{
    priority_queue<int, vector<int>, greater<int>> gq;
    for (int i = 0; i < size; i++)
    {
        gq.push(a[i]);
    }
    int ans = 0;
    while (gq.size() > 1)
    {
        int first = gq.top();
        gq.pop();
        int second = gq.top();
        gq.pop();
        int sum = first + second;
        ans += sum;
        gq.push(sum);
    }
    return ans;
}

int main()
{
    int a[] = {2, 5, 4, 8, 6, 9};
    int size = sizeof(a)/sizeof(a[0]);
    cout << minCost(a, size);
    return 0;
}