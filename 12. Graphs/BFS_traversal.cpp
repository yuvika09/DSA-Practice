#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int v, vector<int> adj[])
{
    int vis[v] = {0}; // 0 based indexing
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return ans;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = bfsTraversal(v, adj);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

// INPUT -
// 9 9
// 0 1
// 0 5
// 1 2
// 1 3
// 3 4
// 4 7
// 6 7
// 5 6
// 5 8