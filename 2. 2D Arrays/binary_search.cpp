#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int st = 0, end = row * col - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        int midEle = matrix[mid / col][mid % col];
        if (midEle == target)
        {
            return 1;
        }
        else if (midEle < target)
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
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

    cout << searchMatrix(matrix, 329);
    return 0;
}