#include <bits/stdc++.h>
#define ll long long
#define n 8
using namespace std;

bool isSafe(int board[n][n], int row, int col)
{
    /* Check this row on left side */
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    /* Check upper diagonal on left side */
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    /* Check lower diagonal on left side */
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

bool nQueen(int board[n][n], int row)
{
    if (row == n)
        return 1;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            if (nQueen(board, row + 1))
                return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    int board[n][n] = {0};
    if (nQueen(board, 0) == 0)
    {
        cout << "No soln exist";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            printf("\n");
        }
    }
    return 0;
}