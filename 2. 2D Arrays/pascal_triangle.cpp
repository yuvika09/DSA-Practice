#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> tri(numRows);
    for (int i = 0; i < numRows; i++)
    {
        tri[i].resize(i + 1);
        tri[i][0] = tri[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    return tri;
}

vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex+1);
    int res = 1;
    row[0] = 1;
    for (int i = 0; i < rowIndex; i++)
    {
        res *= (rowIndex - i);
        res /= (i + 1);
        row[i+1] = res;
    }
    return row;
}

int main()
{
    // vector<vector<int>> matrix = generate(5);
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int n = 30;
    vector<int> row = getRow(n);
    for (int i = 0; i < n+1; i++)
    {
        cout << row[i] << " ";
    }
    return 0;
}