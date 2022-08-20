// Creating linked list by taking input through array
// and displaying it by iterative and recursive approach
//Counting number of nodes
//Sum of all data of nodes
//Maximum element in the linked list


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
    int CountNode();
    int SumNodes();
    int MaxEle();
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

int LinkedList::CountNode()
{
    Node *p = head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int LinkedList::SumNodes()
{
    Node *p = head;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::MaxEle()
{
    Node *p = head;
    int maxi = INT_MIN;
    while (p)
    {
        maxi = max(maxi, p->data);
        p = p->next;
    }
    return maxi;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 8, 16, 5};
    LinkedList l(A, 8);
    // l.Display();
    // cout << l.CountNode();
    cout << l.MaxEle();
    return 0;
}