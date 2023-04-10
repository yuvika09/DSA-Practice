// Reorder Routes to Make All Paths Lead to the City Zero
// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<pair<int, int>> adj[], vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int child = it.first;
            int sign = it.second;
            if (!vis[child])
            {
                count += sign;
                dfs(adj, vis, child);
            }
        }
    }

public:
    int count = 0;
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : connections)
        {
            adj[it[0]].push_back({it[1], 1}); // real edge
            adj[it[1]].push_back({it[0], 0}); // fake edge
        }

        vector<int> vis(n);
        dfs(adj, vis, 0);
        return count;
    }
};