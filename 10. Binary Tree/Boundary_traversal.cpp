
//HARD X

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
        int data = val;
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

bool isLeaf(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
    // return (root->left == NULL && root->right == NULL);
}

void addLeftBoundary(node *root, vector<int> &res)
{
    node *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr)) // not a leaf node
        {
            res.push_back(curr->data);
        }
        if (curr->left)
        {
            curr = curr->left;
        }
        else // if left does not exist then right
        {
            curr = curr->right;
        }
    }
}

void addLeaves(node *root, vector<int> &res)
{
    if (isLeaf(root)) // if leaf node
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}

void addRightBoundary(node *root, vector<int> &res)
{
    node *curr = root->right;
    vector<int> v;
    while (curr)
    {
        if (!isLeaf(curr)) // not a leaf node
        {
            v.push_back(curr->data);
        }
        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        res.push_back(i);
    }
}

vector<int> boundaryTraversal(node *root)
{
    vector<int> res;
    if (root == NULL) // if tree is empty
    {
        return res;
    }
    if (isLeaf(root) == 0) // if root node is not a leaf node
    {
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main()
{
    // 1 2 3 -1 4 5 -1 -1 6 -1 -1 -1 7 -1 8 9 10 -1 -1 11 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);
    vector<int> vec = boundaryTraversal(root);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    return 0;
}