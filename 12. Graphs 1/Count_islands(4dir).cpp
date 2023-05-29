#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0')
    {
        return;
    }
    grid[row][col] = '0'; // Set the location to 0 as it is now visited.
    dfs(row - 1, col, grid);
    dfs(row + 1, col, grid);
    dfs(row, col - 1, grid);
    dfs(row, col + 1, grid);
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (grid[row][col] == '1')
            {
                count++;
                dfs(row, col, grid);
            }
        }
    }
    return count;
}