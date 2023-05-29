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
public:
    int maxi = 0;
    void findPath(TreeNode *root, int dir, int len)
    {
        if (!root)
        {
            return;
        }
        maxi = max(maxi, len);
        findPath(root->left, 0, dir ? len + 1 : 1);
        findPath(root->right, 1, dir ? 1 : len + 1);
    }
    int longestZigZag(TreeNode *root)
    {
        findPath(root, 0, 0);  // 0 for left
        findPath(root, 1, 0); // 1 for right
        return maxi;
    }
};
