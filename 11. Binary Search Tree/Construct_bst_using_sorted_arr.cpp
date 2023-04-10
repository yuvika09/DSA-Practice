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
    TreeNode *bst(int st, int end, vector<int> &nums)
    {
        if (st > end)
        {
            return NULL;
        }

        int mid = (st + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = bst(st, mid - 1, nums);
        root->right = bst(mid + 1, end, nums);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return bst(0, nums.size() - 1, nums);
    }
};