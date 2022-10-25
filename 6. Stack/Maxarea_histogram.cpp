// print out the maximum area in a histogram
// lovebabbar reference


#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmall(vector<int> a, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = a[i];
        while ((s.top() != -1) && a[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top(); // putting idx in vector
        s.push(i);
    }
    return ans;
}

vector<int> prevSmall(vector<int> a, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        while (s.top() != -1 && a[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int maxRectArea(vector<int> a)
{
    int maxArea = INT_MIN;
    int n = a.size();
    vector<int> pS = prevSmall(a, n);
    vector<int> nS = nextSmall(a, n);

    // for(auto i:pS) cout << i << " ";
    // cout << endl;
    // for(auto i:nS) cout << i << " ";

    for (int i = 0; i < n; i++)
    {
        if (nS[i] == -1)
        {
            nS[i] = n;
        }
        int curr = (nS[i] - pS[i] - 1) * a[i];
        maxArea = max(maxArea, curr);
    }
    return maxArea;
}

int main()
{
    vector<int> a = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    cout << maxRectArea(a);
    return 0;
}