//Insertion at begin
//Insertion at end
//insertion at any pos is same as normal ll
//deleting node at begin
//deleting node at END

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

void InsertAtBegin(Node *&head, int val)
{
    Node *n, *temp = head;
    n = new Node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    n->next = head;
    head = n;
    temp->next = n;
}

void InsertAtEnd(Node *&head, int val) // head is taken by reference as we need to modify it
{
    Node *n, *temp = head;
    n = new Node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void DeleteAtStart(Node *&head){
    Node *temp = head, *first = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = first->next;
    temp->next = first->next;
    delete first;    
}

void DeleteAtEnd(Node *&head){
    Node *temp = head, *prev;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    delete temp;    
}

void Display(Node *&head)
{
    Node *temp = head;
    //we cannot use temp!=head, as we are already on head.
    //or we can use do while instead of while
    while (temp->next!=head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}

int main()
{
    Node *head = NULL;
    // InsertAtBegin(head, 9);
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    DeleteAtEnd(head);
    // DeleteAtStart(head);
    Display(head);
    return 0;
}