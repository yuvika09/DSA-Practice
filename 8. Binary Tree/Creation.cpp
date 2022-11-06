#include <iostream>
#include <queue>
#include <stack>
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

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}



int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);

    // cout << "Level order traversal : " << endl;
    // levelOrderTraversal(root);

    cout << "Inorder Traversal is : " << endl;
    inorderTraversal(root);
    
    // cout << "Preorder Traversal is : " << endl;
    // preorderTraversal(root);

    // cout << "Postorder Traversal is : " << endl;
    // postorderTraversal(root);
    return 0;
}
