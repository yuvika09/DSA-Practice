#include <bits/stdc++.h>
using namespace std;

//APPROACH 1 - Using 3*O(n) for checking block is safe or not.

bool isSafe(int row, int col, vector<string> board, int n)
{
    int r = row, c = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = r, col = c;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = r, col = c;
    while (col >= 0 && row < n)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++) // loop for row
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
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

    solve(0, board, ans, n);

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