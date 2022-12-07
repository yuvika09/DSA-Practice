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
    // cout << "Enter data for node: " << endl;
    cin >> val;
    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }
    // cout << "Enter data for left of " << val << endl;
    root->left = buildTree(root->left);

    // cout << "Enter data for right of " << val << endl;
    root->right = buildTree(root->right);
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced1(node *root) // O(n^2)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && isBalanced1(root->left) && isBalanced1(root->right));
}

int dfsHeight(node *root)   //O(n)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = dfsHeight(root->left);
    if (lh == -1)
    {
        return -1;
    }
    int rh = dfsHeight(root->right);
    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }
    return max(lh, rh) + 1;
}

bool isBalanced2(node *root)
{
    return dfsHeight(root) != 1;
}

int main()
{
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);
    cout << isBalanced1(root);

    return 0;
}