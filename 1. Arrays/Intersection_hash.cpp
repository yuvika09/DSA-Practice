// Intersection of 2 arrays using hashing

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void intersect(int a1[], int a2[], int s1, int s2)
{
    unordered_set<int> s;
    int count = 0;
    vector<int> v;
    for (int i = 0; i < s1; i++)
    {
        s.insert(a1[i]);
    }
    for (int i = 0; i < s2; i++)
    {
        if (s.find(a2[i]) != s.end())
        {
            count++;
            v.push_back(a2[i]);
        }
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int a1[4] = {1, 4, 6, 8};
    int a2[4] = {4, 6, 3, 9};
    int s1 = sizeof(a1) / sizeof(a1[0]);
    int s2 = sizeof(a2) / sizeof(a2[0]);
    intersect(a1, a2, s1, s2);
    return 0;
}