#include <bits/stdc++.h>
using namespace std;

//Using 2 arrays visited and path visited
bool checkDfs(int node, int vis[], int pathVis[], vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkDfs(it, vis, pathVis, adj))
            {
                return true;
            }
        }
        else if (pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

//Using same array for both purposes
bool dfs(int node, int vis[], vector<int> adj[])
{
    vis[node] = 2;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj) == true)
            {
                return true;
            }
        }
        else if (vis[i] == 2)
        {
            return true;
        }
    }
    vis[node] = 1;
    return false;
}

bool isCyclic(int v, vector<int> adj[])
{
    int vis[v] = {0};
    int pathVis[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (checkDfs(i, vis, pathVis, adj))
            {
                return true;
            }
        }
    }
    return false;
}