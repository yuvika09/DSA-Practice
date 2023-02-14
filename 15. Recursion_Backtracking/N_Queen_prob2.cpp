#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 - Using hashing

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) // loop for row
    {
        if (leftRow[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) // means no queen placed in that col, upperdiag and lowerdiag
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.'); // made a string s having size n containing ...
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}