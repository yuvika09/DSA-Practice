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

// APPROACH 1 - Using recursion
// TC - O(N) SC - O(N)

class Solution1
{

    TreeNode *prev = NULL;

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// APPROACH 2 - Using Morris Traversal
// TC - O(N) SC - O(1)

class Solution2
{

    TreeNode *prev = NULL;

public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *pre = cur->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};