// Given a sorted dictionary of an alien language having N words and k starting alphabets

#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int v, vector<int> adj[])
{
    int indegree[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        // removal from indegree as node is in toposort
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
            {
                q.push(it);
            }
        }
    }
    return ans;
}

string findOrder(string dict[], int n, int k)
{
    vector<int> adj[k];
    for (int i = 0; i < n - 1; i++) // checking pairs so n-1 used
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int l = min(s1.length(), s2.length());
        for (int j = 0; j < l; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans += char(it + 'a');
    }
    return ans;
}