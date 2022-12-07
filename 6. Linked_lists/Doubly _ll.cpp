// Insertion at begin, at any position between ll, at end
// Deletion at begin, at any position between ll, at end

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void InsertAtBegin(Node *&head, int val)
{
    Node *newNode;
    newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void InsertAtPos(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        InsertAtBegin(head, val);
    }
    Node *newNode, *temp1, *temp2 = head;
    newNode = new Node(val);
    int count = 1;
    while (temp2 && count <= pos)
    {
        temp1 = temp2;
        temp2 = temp2->next;
        count++;
    }
    newNode->next = temp1->next;
    newNode->prev = temp2->prev;
    temp1->next = newNode;
    temp2->prev = newNode;
}

void InsertAtEnd(Node *&head, int val)
{
    if (head == NULL)
    {
        InsertAtBegin(head, val);
    }
    Node *newNode, *temp = head;
    newNode = new Node(val);
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
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

void DeleteAtBegin(Node *&head)
{
    Node *temp = head;
    temp->next->prev = NULL;
    head = head->next;
    delete temp;
}

void DeleteAtPos(Node *&head, int pos)
{
    Node *temp = head;
    int count = 1;
    while (temp && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

void DeleteAtEnd(Node *&head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

int main()
{
    Node *head = NULL;
    InsertAtBegin(head, 1);
    InsertAtBegin(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);

    Display(head);
    // DeleteAtPos(head, 2);
    // DeleteAtBegin(head);
    // DeleteAtEnd(head);
    InsertAtPos(head, 99, 3);
    Display(head);
    return 0;
}
