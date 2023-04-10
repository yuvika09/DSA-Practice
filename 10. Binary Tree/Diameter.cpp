#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------------------------------------
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Approach 1 -> O(n^2) 

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
int diameter1(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter1(root->left);
    int d3 = diameter1(root->right);
    return max(d1, max(d2, d3));
}


//Approach 2 -> O(n) 

int height(TreeNode *root, int &dia)
{
    if (!root)
    {
        return 0;
    }
    int lh = height(root->left, dia);
    int rh = height(root->right, dia);
    dia = max(dia, lh + rh);
    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int dia = 0;
    height(root, dia);
    return dia;
}