//Symmetric tree or tree having mirror image in itself

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode *r1, TreeNode *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    else if ((r1 && !r2) || (!r1 && r2))
    {
        return false;
    }
    return ((r1->val == r2->val) && isSame(r1->left, r2->right) && isSame(r1->right, r2->left));
}

bool isSymmetric(TreeNode *root)
{
    return (isSame(root->left, root->right));
}