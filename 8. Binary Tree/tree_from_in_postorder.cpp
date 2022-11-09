// MEDIUM  X

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

node *build(vector<int> inorder, int inSt, int inEnd, vector<int> postorder, int postSt, int postEnd, map<int, int> &inMap)
{
    if (postSt > postEnd || inSt > inEnd)
    {
        return NULL;
    }

    node *root = new node(postorder[postEnd]);
    int inroot = inMap[postorder[postEnd]];
    int numleft = inroot - inSt;

    root->left = build(inorder, inSt, inroot - 1, postorder, postSt, postSt + numleft - 1, inMap);
    root->right = build(inorder, inroot + 1, inEnd, postorder, postSt + numleft, postEnd - 1, inMap);
    return root;
}

node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
    {
        return NULL;
    }
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++)
    {
        inMap[inorder[i]] = i;
    }
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> in{4, 2, 5, 1, 6, 3};
    vector<int> post{4, 5, 2, 6, 3, 1};

    node *root = NULL;
    root = buildTree(in, post);
    cout << "Inorder Traversal is : " << endl;
    inorderTraversal(root);
    return 0;
}