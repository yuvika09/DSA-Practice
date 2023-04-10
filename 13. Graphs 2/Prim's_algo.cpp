#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);

    pq.push({0, 0}); //{wt, node}
    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        int wt = it.first;
        int node = it.second;
        pq.pop();

        if (vis[node])
        {
            continue;
        }
        //when we add to mst
        vis[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edWt = it[1];
            if (!vis[adjNode])
            {
                pq.push({edWt, adjNode});
            }
        }
    }
    return sum;
}