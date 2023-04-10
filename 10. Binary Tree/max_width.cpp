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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    long long res = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        long long s = q.size();
        long long mini = q.front().second;
        long long first, last;

        for (int i = 0; i < s; i++)
        {
            long long cur_idx = q.front().second - mini;
            TreeNode *cur_node = q.front().first;
            q.pop();

            if (i == 0) // store the starting idx
            {
                first = cur_idx;
            }
            if (i == s - 1) // store the ending idx
            {
                last = cur_idx;
            }
            if (cur_node->left)
            {
                q.push({cur_node->left, (2 * cur_idx) + 1});
            }
            if (cur_node->right)
            {
                q.push({cur_node->right, (2 * cur_idx) + 2});
            }
        }
        res = max(res, last - first + 1);
    }
    return res;
}