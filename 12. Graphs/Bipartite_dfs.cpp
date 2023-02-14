#include <bits/stdc++.h>
using namespace std;

bool checkDfs(int node, int col, vector<int> adj[], int color[])
{
    color[node] = col;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!checkDfs(it, !col, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int v, vector<int> adj[])
{
    int color[v];
    for (int i = 0; i < v; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (!checkDfs(i, 0, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}