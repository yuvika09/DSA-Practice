#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int stR = 0, stC = 0, endR = row - 1, endC = col - 1;
    int count = 0, num = row * col;
    while (count < num)
    {
        for (int i = stC; count < num && i <= endC; i++)
        {
            ans.push_back(matrix[stR][i]);
            count++;
        }
        stR++;
        for (int i = stR; count < num && i <= endR; i++)
        {
            ans.push_back(matrix[i][endC]);
            count++;
        }
        endC--;
        for (int i = endC; count < num && i >= stC; i--)
        {
            ans.push_back(matrix[endR][i]);
            count++;
        }
        endR--;
        for (int i = endR; count < num && i >= stR; i--)
        {
            ans.push_back(matrix[i][stC]);
            count++;
        }
        stC++;
    }
    return ans;
}
//feed 1 to n^2 in spiral form in the matrix
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int left = 0, top = 0, right = n - 1, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = num;
            num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = num;
            num++;
        }
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; i--)
            {
                ans[bottom][i] = num;
                num++;
            }
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = num;
                num++;
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> ans = spiralOrder(matrix);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}