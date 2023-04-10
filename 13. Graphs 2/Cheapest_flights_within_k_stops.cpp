// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    vector<int> dist(n, 1e9);
    q.push({0, {0, src}});  //({stops, {dis, node}})
    dist[src] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        int stops = it.first;
        int cost = it.second.first;
        int node = it.second.second;
        q.pop();

        if (stops > k)
        {
            continue;
        }
        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edWt = iter.second;
            if (cost + edWt < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = cost + edWt;
                q.push({stops + 1, {cost + edWt, adjNode}});
            }
        }
    }
    if (dist[dst] == 1e9)
    {
        return -1;
    }
    return dist[dst];
}
