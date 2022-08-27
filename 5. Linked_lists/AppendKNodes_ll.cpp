// Appending k nodes from end to the start of the ll


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
int Length(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *AppendKNodes(Node *&head, int k)
{
    Node *newTail, *newHead, *temp = head;
    int len = Length(head);
    k = k%len;    //if k is given greater than length of ll
    int count = 1;
    while (temp->next)
    {
        if(count == len-k){
            newTail = temp;
        }
        if(count == len-k+1){
            newHead = temp;
        }
        temp = temp->next;
        count++;
    }
    newTail->next = NULL;
    temp->next = head;
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

    Display(head);
    Node *newHead = AppendKNodes(head, 2);
    Display(newHead);
    return 0;
}
