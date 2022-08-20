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
    bool SortedOrNot();
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

bool LinkedList::SortedOrNot(){
    
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 8, 16, 5};
    LinkedList l(A, 8);

    return 0;
}