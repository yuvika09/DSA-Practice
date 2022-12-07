//MEDIUM  X

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
        int data = val;
        left = NULL;
        right = NULL;
    }
};

node *createTree(vector<int> &pre, int preSt, int preEnd, vector<int> &in, int inSt, int inEnd, map<int, int> &inMap)
{
    if (preSt > preEnd || inSt > inEnd)
    {
        return NULL;
    }
    node *root = new node(pre[preSt]);
    int inRoot = inMap[pre[preSt]];
    int numsLeft = inRoot - inSt;

    root->left = createTree(pre, preSt + 1, preSt + numsLeft, in, inSt, inRoot - 1, inMap);
    root->right = createTree(pre, preSt + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, inMap);
    return root;
}

node *buildTree(vector<int> &in, vector<int> &pre)
{
    if (in.size() != pre.size())
    {
        return NULL;
    }
    map<int, int> inMap;
    for (int i = 0; i < in.size(); i++)
    {
        inMap[in[i]] = i;
    }
    node *root = createTree(pre, 0, pre.size() - 1, in, 0, in.size() - 1, inMap);
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
    vector<int> in{9, 3, 15, 20, 7};
    vector<int> pre{3, 9, 20, 15, 7};
    
    node *root =NULL;
    root = buildTree(in, pre);
    levelOrderTraversal(root);
    return 0;
}