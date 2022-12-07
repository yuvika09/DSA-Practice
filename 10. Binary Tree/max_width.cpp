//this solution might give a overflow condn 
//use long long instead of int

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

node *buildTree(node *root)
{
    int val;
    cin >> val;
    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

int maxWidth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int res = 1;
    queue<pair<node *, int>> q;
    q.push({root, 1});
    while (!q.empty())
    {
        int temp = q.back().second - q.front().second + 1; // width (last-first+1)
        res = max(res, temp);
        for (int i = 0; i < q.size(); i++)
        {
            pair<node *, int> p = q.front();
            int idx = p.second;
            q.pop();
            if (p.first->left)
            {
                q.push({p.first->left, 2 * idx});
            }
            if (p.first->right)
            {
                q.push({p.first->right, (2 * idx) + 1});
            }
        }
    }
    return res;
}

int main()
{
    // 10 2 4 -1 -1 5 -1 -1 3 -1 60 -1 -1
    node *root = NULL;
    root = buildTree(root);

    cout << maxWidth(root);

    return 0;
}