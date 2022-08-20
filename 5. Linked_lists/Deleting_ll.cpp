// Creating a linked list using insert function
// Deleting a node in linked list

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
    void InsertNode(int index, int data);
    int DeleteNode(int index);
    void Display();
};

void LinkedList::InsertNode(int index, int data)
{
    Node *newNode, *temp;
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (index == 0) // if inserted at first position
    {
        newNode->next = head;
        head = newNode;
    }
    else // if inserted elsewhere
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

int LinkedList::DeleteNode(int index)
{
    Node *temp = head, *prev = head;
    int delEle;
    if (index == 1)                    //if deletion at first position
    {
        head = temp->next;
        delEle = temp->data;
        delete temp;
    }
    else
    {
        for (int i = 1; i < index; i++)       //if deletion at given index
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delEle = temp->data;
        delete temp;
    }
    return delEle;
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

int main()
{
    LinkedList l;
    l.InsertNode(0, 2);
    l.InsertNode(1, 6);
    l.InsertNode(2, 7);
    l.InsertNode(3, 17);
    l.InsertNode(4, 47);
    l.DeleteNode(3);
    l.Display();
}