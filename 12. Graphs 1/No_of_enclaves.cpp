//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid)
{
    grid[row][col] = 0;
    int n = grid.size();
    int m = grid[0].size();
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        if (newRow >= 0 && newCol >= 0 && newRow <= n - 1 && newCol <= m - 1 && grid[newRow][newCol] == 1)
        {
            dfs(newRow, newCol, grid);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i * j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}