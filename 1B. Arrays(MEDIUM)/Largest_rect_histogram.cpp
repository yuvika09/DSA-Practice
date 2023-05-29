#include <bits/stdc++.h>
#define ll long long
using namespace std;

// APPROACH 2 - using 2 arrays and 1 stack

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftSm[n], rightSm[n];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            leftSm[i] = 0;
        }
        else
        {
            leftSm[i] = st.top() + 1;
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rightSm[i] = n - 1;
        }
        else
        {
            rightSm[i] = st.top() - 1;
        }
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (rightSm[i] - leftSm[i] + 1));
    }
    return ans;
}

// APPROACH 1 - using 1 stack only (1 pass)

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int ht = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }
            ans = max(ans, ht * width);
        }
        st.push(i);
    }
    return ans;
}
