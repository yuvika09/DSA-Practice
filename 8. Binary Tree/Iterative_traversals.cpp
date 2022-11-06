// level order traversal is also considered as iterative traversal

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

vector<int> iterativeInorder(node *root)
{
    stack<node *> st;
    node *temp = root;
    vector<int> in;
    while (1)
    {
        if (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
        else // temp == NULL
        {
            if (st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            in.push_back(temp->data);
            temp = temp->right;
        }
    }
    return in;
}

vector<int> iterativePreorder(node *root)
{
    vector<int> pre;
    if (root == NULL)
    {
        return pre;
    }
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        pre.push_back(root->data);
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
    }
    return pre;
}

vector<int> iterativePostOrder(node *root)
{
    vector<int> post;
    if (root == NULL)
    {
        return post;
    }
    stack<node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left)
        {
            s1.push(root->left);
        }
        if (root->right)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        post.push_back(s2.top()->data);
        s2.pop();
    }
    return post;
}

void All_in_one_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<pair<node *, int>> s;
    vector<int> pre, post, in;

    s.push({root, 1}); // Push Root Element with Count = 1

    while (!s.empty())
    {
        auto it = s.top();
        s.pop();

        if (it.second == 1) // PREORDER
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->left)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) // INORDER
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right)
            {
                s.push({it.first->right, 1});
            }
        }
        else if (it.second == 3) // POSTORDER
        {
            post.push_back(it.first->data);
            // s.pop();
        }
    }
    // Printing Pre-Order
    for (int i = 0; i < pre.size(); i++)
        cout << pre[i] << " ";
    cout << endl;
    // Printing In-Order
    for (int i = 0; i < in.size(); i++)
        cout << in[i] << " ";
    cout << endl;
    // Printing Post Order
    for (int i = 0; i < post.size(); i++)
        cout << post[i] << " ";
    cout << endl;
}

void trav(node *root, vector<int> &in, vector<int> &pre, vector<int> &post)
{
    if (root == NULL)
    {
        return;
    }
    pre.push_back(root->data);
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);

    // cout << "Inorder Traversal is : " << endl;
    // vector<int> v = iterativeInorder(root);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }

    // cout << "Preorder Traversal is : " << endl;
    // vector<int> v = iterativeInorder(root);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }

    // cout << "Postorder Traversal is : " << endl;
    // vector<int> v = iterativePostOrder(root);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }

    All_in_one_traversal(root);

    // vector<int> pre, post, in;
    // trav(root, in, pre, post);
    // for (int i = 0; i < pre.size(); i++)
    //     cout << pre[i] << " ";
    // cout << endl;
    // // Printing In-Order
    // for (int i = 0; i < in.size(); i++)
    //     cout << in[i] << " ";
    // cout << endl;
    // // Printing Post Order
    // for (int i = 0; i < post.size(); i++)
    //     cout << post[i] << " ";
    // cout << endl;

    return 0;
}
