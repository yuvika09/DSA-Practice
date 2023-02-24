#include <bits/stdc++.h>
using namespace std;

bool topoSort(int v, vector<int> adj[])
{ 
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        // removal from indegree as node is in toposort
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
            {
                q.push(it);
            }
        }
    }
    if (count == v)
    {
        return false;
    }
    return true;
}