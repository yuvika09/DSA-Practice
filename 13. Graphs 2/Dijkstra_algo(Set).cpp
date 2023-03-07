#include <bits/stdc++.h>
using namespace std;
// Incase of PQ, the maximum heap size can go upto E = number of edges, leading to complexity = O(E*logE).
//  Incase of set, the maximum set size can go upto V =. number of vertices, leading to complexity = O(E*logV).

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    st.insert({0, S});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (dis + edgeWt < dist[adjNode])
            {
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}