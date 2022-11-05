#include <iostream>
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

int size(node *root) // total number of nodes in the tree
{
    if (root == NULL)
    {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int maxNode(node *root) // maximum data of node stored in the tree
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxNode(root->left), maxNode(root->right)));
}

void printkDist(node *root, int k)  //prints out the nodes at the distance k from the root node /or/ the (k+1)th level
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        printkDist(root->left, k - 1);
        printkDist(root->right, k - 1);
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    // cout << height(root) << endl;
    // cout << size(root) << endl;
    // cout << maxNode(root) << endl;
    printkDist(root, 2);
    return 0;
}