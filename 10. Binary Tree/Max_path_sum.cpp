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
    int maxPathDown(TreeNode *root, int &maxi)
    {
        if (!root)
        {
            return 0;
        }
        int leftMaxSum = max(0, maxPathDown(root->left, maxi));
        int rightMaxSum = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, leftMaxSum + rightMaxSum + root->val);
        return max(leftMaxSum, rightMaxSum) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};