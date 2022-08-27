// Creating linked list using one class Node
// Merging two sorted linked lists
// 1) using dummy node to start(dummyNode->next = head)
// 2) using recursive fn

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertAtEnd(Node *&head, int val) // head is taken by reference as we need to modify it
{
    Node *n, *temp = head;
    n = new Node(val);

    if (head == NULL) // no nodes present
    {
        head = n;
        return;
    }
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Display(Node *head)
// taking head as value so it cannot change
// we can also traverse using head instead of temp
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *Merge(Node *&head1, Node *&head2)
{
    Node *p1 = head1, *p2 = head2;
    Node *dummyNode = new Node(-1);
    Node *p3 = dummyNode;
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode->next;
}

Node *MergeRecursive(Node *&head1, Node *&head2)
{
    if (head1 == NULL) // no element left in ll1 - returning ll2
    {
        return head2;
    }
    if (head2 == NULL) // no element left in ll2
    {
        return head1;
    }
    Node *result; // result points node which is to be included in final list
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = MergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = MergeRecursive(head1, head2->next);
    }
    return result;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int arr1[4] = {1, 3, 5, 6};
    int arr2[4] = {2, 4, 7, 9};
    for (int i = 0; i < 4; i++)
    {
        InsertAtEnd(head1, arr1[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        InsertAtEnd(head2, arr2[i]);
    }
    Display(head1);
    Display(head2);
    // Node *head3 = MergeRecursive(head1, head2);
    Node *head3 = Merge(head1, head2);
    Display(head3);
    return 0;
}