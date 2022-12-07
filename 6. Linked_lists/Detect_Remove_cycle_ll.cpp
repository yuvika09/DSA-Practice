// Make a cycle in ll
// Detect the cycle in the ll
// Remove the cycle from the ll

//(FLOYD'S ALGORITHM)
//(HARE AND TORTOISE ALGORITHM)

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

void CreateCycle(Node *&head, int pos)
{
    Node *temp = head, *start = head;
    int count = 1;
    while (temp->next)
    {
        if (count == pos)
        {
            start = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = start;
}

bool DetectCycle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true; // cycle is present
        }
    }
    return false;
}

void RemoveCycle(Node *head)
{
    Node *slow = head, *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main()
{
    Node *head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    CreateCycle(head, 2);
    cout << DetectCycle(head) << endl;
    RemoveCycle(head);
    cout << DetectCycle(head) << endl;
    Display(head);
    // Display(head);
    return 0;
}
