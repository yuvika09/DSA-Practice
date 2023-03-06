// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> image, int iniCol, int newColor)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size(); 
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniCol && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, iniCol, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int iniCol = image[sr][sc];
    vector<vector<int>> ans = image;

    dfs(sr, sc, ans, image, iniCol, newColor);
    return ans;
}