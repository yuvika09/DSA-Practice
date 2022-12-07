// Elements in each row are sorted in ascending from left to right.
// Elements in each column are sorted in ascending from top to bottom.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int rowIdx = 0, colIdx = col - 1;
    while (rowIdx < row && colIdx >= 0)
    {
        int ele = matrix[rowIdx][colIdx];
        if (ele == target)
        {
            return 1;
        }
        else if (target < ele)
        {
            colIdx--;
        }
        else
        {
            rowIdx++;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << searchMatrix(matrix, 9);
    return 0;
}