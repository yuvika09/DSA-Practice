// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands

#include <bits/stdc++.h>
    using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid)
{
    grid[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0)
        {
            dfs(nrow, ncol, grid);
        }
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Boundary DFS
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i * j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, grid);
                }
            }
        }
    }

    // DFS for remaining grid
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                ans++;
                dfs(i, j, grid);
            }
        }
    }
    return ans;
}
