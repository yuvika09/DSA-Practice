// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// Given input is in the form of adjaceny matrix.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLst[], int vis[])
{
    vis[node] = 1;
    for (auto it : adjLst[node])
    {
        if (!vis[it])
        {
            dfs(it, adjLst, vis);
        }
    }
}

int countProvinces(vector<vector<int>> adjMat, int v)
{
    vector<int> adjLst[v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMat[i][j] == 1 && i != j)
            {
                adjLst[i].push_back(j);
                adjLst[j].push_back(i);
            }
        }
    }
    int vis[v] = {0};
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjLst, vis);
        }
    }
    return count;
}