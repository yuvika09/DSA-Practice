#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ans);
        }
    }
}

vector<int> dfsTraversal(int v, vector<int> adj[])
{
    int vis[v] = {0}; // 0 based indexing
    vector<int> ans;
    int start = 0;
    dfs(start, adj, vis, ans);
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

    vector<int> ans = dfsTraversal(v, adj);
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