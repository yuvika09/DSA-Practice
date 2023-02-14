#include <bits/stdc++.h>
using namespace std;

bool detectDfs(int node, int parent, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (detectDfs(it, node, adj, vis))
            {
                return true;
            }
        }
        else
        {
            if (it != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    int vis[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (detectDfs(i, -1, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}