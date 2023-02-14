#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int pos;
    int dead;
    int profit;
};

bool comp(Job a, Job b)
{
    if (a.profit > b.profit)
    {
        return true;
    }
    return false;
}

pair<int, int> jobScheduling(int prof[], int dead[], int n)
{
    struct Job j[n];
    int maxDead = 0;
    for (int i = 0; i < n; i++)
    {
        j[i].pos = i + 1;
        j[i].dead = dead[i];
        j[i].profit = prof[i];
        maxDead = max(maxDead, dead[i]);
    }
    vector<int> slot(maxDead + 1, -1);
    sort(j, j + n, comp);

    int count = 0, totalProf = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = j[i].dead; k > 0; k--)
        {
            if (slot[k] == -1)
            {
                slot[k] = j[i].pos;
                count++;
                totalProf += j[i].profit;
                break;
            }
        }
    }
    // for (auto i : slot)
    // {
    //     cout << i << " ";
    // }
    return make_pair(count, totalProf);
}

int main()
{
    int prof[] = {100, 19, 27, 25, 15};
    int dead[] = {2, 1, 2, 1, 1};
    int n = sizeof(prof) / sizeof(prof[0]);
    pair<int, int> p = jobScheduling(prof, dead, n);
    cout << p.first << " " << p.second;
}