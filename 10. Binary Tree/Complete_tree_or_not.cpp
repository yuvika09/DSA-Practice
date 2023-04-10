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

class Solution
{
private:
    int countNode(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return (1 + countNode(root->left) + countNode(root->right));
    }

    bool dfs(TreeNode *root, int idx, int n)
    {
        if (!root)
        {
            return true;
        }
        if (idx >= n)
        {
            return false;
        }
        return (dfs(root->left, 2 * idx + 1, n) && dfs(root->right, 2 * idx + 2, n));
    }

public:
    bool isCompleteTree(TreeNode *root)
    {
        int n = countNode(root);
        return dfs(root, 0, n);
    }
};