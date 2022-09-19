// Using Moore's Voting Algorithm

#include <bits/stdc++.h>
using namespace std;
#define n 5

int majEle(int arr[])
{
    int ansIndex = 0, count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[ansIndex])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            ansIndex = i;
            count = 1;
        }
    }
    int co = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[ansIndex])
        {
            co++;
        }
    }
    if (co > (n / 2))
        return arr[ansIndex];
    return -1;
}

int main()
{
    int arr[n] = {5, 1, 4, 1, 1};
    cout << majEle(arr);
    return 0;
}