// MEDIUM

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

void leftView(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftView(root->left, ans, level + 1);
    leftView(root->right, ans, level + 1);
}

void rightView(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftView(root->right, ans, level + 1);
    leftView(root->left, ans, level + 1);
}

void topView(node *root, vector<int> &ans)
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
        if (m.find(line) == m.end())
        {
            m[line] = temp->data;
        }
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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL) // if current level is traversed
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
                // means more elements are left to traverse so add null in the queue
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // 10 2 4 -1 -1 5 -1 -1 3 -1 60 -1 -1
    node *root = NULL;
    root = buildTree(root);

    cout << "Level order traversal : " << endl;
    levelOrderTraversal(root);

    // cout << "Left View of the tree is: " << endl;
    // vector<int> ans1;
    // leftView(root, ans1, 0);
    // for (auto i : ans1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "Right View of the tree is: " << endl;
    // vector<int> ans2;
    // rightView(root, ans2, 0);
    // for (auto i : ans2)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << "Top View of the tree is: " << endl;
    // vector<int> ans3;
    // topView(root, ans3);
    // for (auto i : ans3)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << "Bottom View of the tree is: " << endl;
    vector<int> ans4;
    bottomView(root, ans4);
    for (auto i : ans4)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}