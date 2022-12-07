// C++ programs for
// Searching a node in linked list
// Inserting node in linked list by index
// Inserting node in sorted linked list

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
    int SearchNode(int n);
    void InsertNode(int index, int data);
    void InsertSorted(int data);
    void Display();
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

int LinkedList::SearchNode(int ele)
{
    Node *temp = head;
    int index = 0;
    while (temp)
    {
        if (temp->data == ele)
        {
            cout << "Element found at " << index << endl;
            return 0;
        }
        index++;
        temp = temp->next;
    }
    cout << "Element not found" << endl;
    return 0;
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

void LinkedList::InsertNode(int index, int data)
{
    Node *newNode, *temp;
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (index == 0)                    //if inserted at first position
    {
        newNode->next = head;
        head = newNode;
    }
    else                              //if inserted elsewhere
    {
        temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void LinkedList::InsertSorted(int data)
{
    Node *newNode, *temp = head, *prev = head;
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    while (temp && temp->data < data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == head)           //if data is smaller than first node's data
    {
        newNode->next = head;
        head = newNode;
    }
    else                        //if anywhere between nodes
    {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}  

int main()
{
    int A[] = {1, 2, 3, 4, 5, 8, 16};
    LinkedList l(A, 7);
    // l.InsertSorted(78);
    l.InsertNode(7, 67);
    l.Display();
    return 0;
}