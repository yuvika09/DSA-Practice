
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


int main()
{
    Node *head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);

    Display(head);
    return 0;
}