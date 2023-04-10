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

void dfs(TreeNode *root, int &ans, int temp) // ans passed by refernece while not temp
// as temp changes when backtrack, while ans reamins same.
{
    temp = temp * 10 + root->val;
    if (!root->left && !root->right)
    {
        ans += temp;
        return;
    }
    if (root->left)
    {
        dfs(root->left, ans, temp);
    }
    if (root->right)
    {
        dfs(root->right, ans, temp);
    }
}

int sumNumbers(TreeNode *root)
{
    int ans = 0;
    dfs(root, ans, 0);
    return ans;
}