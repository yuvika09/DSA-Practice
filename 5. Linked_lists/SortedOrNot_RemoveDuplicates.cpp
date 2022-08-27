// Checking if linked list is sorted or not
// Removing duplicates in a linked list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int A[], int n);
    void Display();
    bool IsSorted();
    void RemoveDup();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *temp, *present;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    present = head;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        present->next = temp;
        present = temp;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool LinkedList::IsSorted()
{
    Node *temp = head;
    int cmp = INT_MIN;
    while (temp)
    {
        if (temp->data < cmp)
        {
            cout << "Not Sorted" << endl;
            return false;
        }
        cmp = temp->data;
        temp = temp->next;
    }
    cout << "Sorted" << endl;
    return true;
}

void LinkedList::RemoveDup()
{
    Node *prev = head, *curr = head->next;     //to avoid first iteration to match
    while (curr)
    {
        if (prev->data == curr->data)          //when duplicate found
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else                                   //when nrml condition found
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 3, 3, 4, 5, 5};
    LinkedList l(A, 8);
    l.IsSorted();
    l.RemoveDup();
    l.Display();
    return 0;
}