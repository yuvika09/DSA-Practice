#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int v, vector<int> adj[])
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
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
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
    return ans;
}