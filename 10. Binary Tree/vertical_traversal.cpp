// DIFFICULT

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

vector<vector<int>> verticalTraversal(node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        node *temp = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->data);
        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto i : nodes)
    {
        vector<int> col;
        for (auto j : i.second) // traversing for map of lvl and multinodes
        {
            col.insert(col.end(), j.second.begin(), j.second.end()); // selecting and inserting nodes of multiset in vector col
            //col.end ensures every node's data is added at the last of present vector
            // inserting all nodes at same vertical having different levels.
        }
        ans.push_back(col); // inserting col in ans(added for one vertical)
    }
    return ans;
}

// int main()
// {
//     node *root = NULL;
//     root = buildTree(root);
//     levelOrderTraversal(root);
//     vector<vector<int>> v = verticalTraversal(root);

//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             cout << v[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }