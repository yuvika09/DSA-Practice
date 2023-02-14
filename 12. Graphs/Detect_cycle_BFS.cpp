#include <bits/stdc++.h>
using namespace std;

bool detectBfs(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
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
            if (detectBfs(i, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}