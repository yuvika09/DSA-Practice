#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeWt = it[1];
            int adjNode = it[0];

            if (dis + edgeWt < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

