#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void bottomView(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *temp = it.first;
        int line = it.second;
        m[line] = temp->data;
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto i : m)
    {
        cout << i.second << " ";
    }
}
