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