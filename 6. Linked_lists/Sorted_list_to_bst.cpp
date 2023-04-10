#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mid(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    ListNode *prev = head;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev)
    {
        prev->next = NULL;
    }
    return slow;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *midd = mid(head);
    TreeNode *root = new TreeNode(midd->val);
    if (head == midd)
    {
        return root;
    }
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midd->next);
    return root;
}