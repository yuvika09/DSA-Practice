#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &matrix, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (matrix[row][i] == c && i != col)
        {
            return false;
        }
        if (matrix[i][col] == c && i != row)
        {
            return false;
        }
        if (matrix[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c && (3 * (row / 3) + i / 3) != row && (3 * (col / 3) + i % 3) != col)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &matrix)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (matrix[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(matrix, i, j, c))
                    {
                        matrix[i][j] = c;
                        if (solveSudoku(matrix) == true)
                        {
                            return true;
                        }
                        else
                        {
                            matrix[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{

    vector<vector<char>> matrix{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(matrix);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
