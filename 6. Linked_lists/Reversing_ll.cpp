// Reversing linked list
// by reversing elements(storing data dynamically)
// by reversing links between nodes
// Reversing by k nodes in a linked list

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

void Display(Node *&head)
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void ReversingByEle(Node *&head)
{
    Node *temp = head, *new1 = head;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    while (new1)
    {
        int x = v[(v.size()) - 1];
        v.pop_back();
        new1->data = x;
        new1 = new1->next;
    }
}

void ReversingByLink(Node *&head)
{
    Node *prev = NULL, *curr = NULL, *new1 = head;
    while (new1)
    {
        prev = curr;
        curr = new1;
        new1 = new1->next;
        curr->next = prev;
    }
    head = curr;
}

// Node *ReverseKnodes(Node *&head, int k)
// {
//     Node *prev = NULL, *curr = head, *new1;
//     int count = 0;
//     while (curr && count<k)
//     {
//         // prev = curr;
//         // curr = new1;
//         // new1 = new1->next;
//         // curr->next = prev;
//         new1=curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = new1;
//         count++;
//     }
//     if (new1)
//     {
//         head->next = ReverseKnodes(new1, k);
//     }
//     return prev;
// }

Node *recReverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    Node *head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 6);
    InsertAtEnd(head, 7);
    InsertAtEnd(head, 8);
    // ReverseKnodes(head, 2);
    // ReversingByEle(head);
    // ReversingByLink(head);
    Display(head);
    cout << endl;
    Node *head2 = recReverse(head);
    Display(head2);
    return 0;
}