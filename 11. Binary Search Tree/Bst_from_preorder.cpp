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
    TreeNode *makeBst(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = makeBst(preorder, i, root->val);
        root->right = makeBst(preorder, i, bound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return makeBst(preorder, i, INT_MAX);
    }
};