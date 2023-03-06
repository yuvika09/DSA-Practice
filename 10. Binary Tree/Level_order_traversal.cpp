#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        val = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl;
        while (size--)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            lvl.push_back(node->val);
        }
        ans.push_back(lvl);
    }
    return ans;
}

node *buildTree(node *root)
{
    // cout << "Enter data for node: " << endl;
    int val;
    cin >> val;
    root = new node(val);
    if (val == -1)
    {
        return NULL;
    }

    // cout << "Enter data for left of " << val << endl;
    root->left = buildTree(root->left);

    // cout << "Enter data for right of " << val << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL) // if current level is traversed
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
                // means more elements are left to traverse so add null in the queue
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}