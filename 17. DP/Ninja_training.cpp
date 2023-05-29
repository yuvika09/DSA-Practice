// A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.

#include <bits/stdc++.h>
using namespace std;

int memofn(vector<vector<int>> &grid, int day, int lastTask, vector<vector<int>> &dp)
{
    if (dp[day][lastTask] != -1)
    {
        return dp[day][lastTask];
    }
    int maxi = 0;
    if (day == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i != lastTask)
            {
                maxi = max(maxi, grid[0][i]);
            }
        }
        return maxi;
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != lastTask)
        {
            int points = grid[day][i] + memofn(grid, day - 1, i, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][lastTask] = maxi;
}

int tabfn(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // can be done using a loop too
    dp[0][0] = max(grid[0][1], grid[0][2]);
    dp[0][1] = max(grid[0][0], grid[0][2]);
    dp[0][2] = max(grid[0][0], grid[0][1]);
    dp[0][3] = max(grid[0][0], max(grid[0][1], grid[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int points = grid[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], points);
                }
            }
        }
    }
    return dp[n - 1][3];
}

int tabfn(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> prev(4, 0);

    // can be done using a loop too
    prev[0] = max(grid[0][1], grid[0][2]);
    prev[1] = max(grid[0][0], grid[0][2]);
    prev[2] = max(grid[0][0], grid[0][1]);
    prev[3] = max(grid[0][0], max(grid[0][1], grid[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], grid[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int ninjaTraining(vector<vector<int>> &grid)
{
    int n = grid.size();                           // days;
    vector<vector<int>> dp(n, vector<int>(4, -1)); // given 3 tasks
    return memofn(grid, n - 1, 3, dp);
    
}
