#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fracKnap(int W, Item arr[], int n)
{
    sort(arr, arr + n, comp);
    int currWt = 0;
    double totalVal = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currWt + arr[i].weight <= W)
        {
            currWt += arr[i].weight;
            totalVal += arr[i].value;
        }
        else
        {
            int remain = W - currWt;
            totalVal += ((double)arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
    return totalVal;
}

int main()
{
    int n = 3, wt = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    cout << fracKnap(wt, arr, n);
    return 0;
}