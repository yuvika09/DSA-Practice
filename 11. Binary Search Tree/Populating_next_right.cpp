// Populating Next Right Pointers in Each Node
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *start = root, *curr;

        while (start && start->left)
        {
            curr = start;
            while (curr && curr->left)
            {
                curr->left->next = curr->right;
                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }
            start = start->left;
        }
        return root;
    }
};