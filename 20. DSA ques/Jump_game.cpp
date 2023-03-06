// Given an array of integers arr, you are initially positioned at the first index of the array.
//  In one step you can jump from index i to index:
//  i + 1 where: i + 1 < arr.length.
//  i - 1 where: i - 1 >= 0.
//  j where: arr[i] == arr[j] and i != j.
//  Return the minimum number of steps to reach the last index of the array.

#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;

    // After doing below three statements our unordered_map looks like this
    // it will store value and vector<int> will store mp of that value
    //-23: [1, 2],
    // 3: [8],
    // 23: [5, 6, 7],
    // 100: [0, 4],
    // 404: [3, 9]

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }
    // queue will store index of adjacent element
    queue<int> q;
    // visited will take care wheather the particular index is visited or not
    vector<bool> visited(n);
    q.push(0);
    visited[0] = true;
    int steps = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int currIndex = q.front();
            q.pop();
            // if currIndex == lastIndex of the array, it means we got the answer and we return the number of steps required to reach at the last index
            if (currIndex == n - 1)
                return steps;
            // below statement will store vector<int> from unordered_map, it means our it will take care of arr[i] == arr[j] && i != j condition
            vector<int> &next = mp[arr[currIndex]];
            // below two statement take care of wheather next jump be i + 1 or i - 1
            next.push_back(currIndex - 1);
            next.push_back(currIndex + 1);
            for (int it : next)
            {
                if (it >= 0 && it < n && !visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                }
            }
            // In the given code, next is used to store the mp of the same value as the current index, and also the mp to which we can jump from the current index (i.e. currIndex + 1 and currIndex - 1).
            // If we do not clear next at the end of each iteration of the while loop, it will keep storing the mp for the same value and also the mp to which we can jump from the previous iterations as well, leading to incorrect results or time limit exceeded.
            // So, including the statement next.clear(); at the end of each iteration of the while loop is important to make sure that the next vector only contains the valid mp for the current iteration.
            next.clear();
        }
        steps++;
    }
    return -1; // unreachable
}