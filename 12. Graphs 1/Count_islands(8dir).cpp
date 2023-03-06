//'0' is water '1' is land
// an island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally in all 8 directions.

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &vis, int row, int col, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1; // marking as visited
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) // traversing the neighbours and mark them if its a land
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++) // changes(delta) in rows for checking neighbours
        {
            for (int delcol = -1; delcol <= 1; delcol++)
            {
                int nrow = r + delrow;
                int ncol = c + delcol;
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])//boundary anf marking condns
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int countIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                count++;
                bfs(vis, row, col, grid);
            }
        }
    }
    return count;
}