#include <bits/stdc++.h>
using namespace std;

bool checkBfs(int st, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(st);
    color[st] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
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
            if (checkBfs(i, adj, color) == false){
                return false;
            }
        }
    }
    return true;
}