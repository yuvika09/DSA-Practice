#include <bits/stdc++.h>
using namespace std;

void makeDfs(int row, int col, vector<pair<int, int>> &v, vector<vector<int>> &grid, vector<vector<int>> &vis, int row0, int col0)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    v.push_back({row - row0, col - col0});
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
        {
            makeDfs(nrow, ncol, v, grid, vis, row0, col0);
        }
    }
}

int countDistinct(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> v;
                makeDfs(i, j, v, grid, vis, i, j);
                st.insert(v);
            }
        }
    }
    return st.size();
}