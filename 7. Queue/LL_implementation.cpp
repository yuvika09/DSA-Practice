// Linked list implementation of Queue
// Insertion at end(Enqueue)
// Deletion from beginning (Dequeue)

#include <bits/stdc++.h>
using namespace std;
#define n 20

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

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void Enque(int val)
    {
        Node *newNode = new Node(val);
        if (front == NULL) // queue empty
        {
            front = newNode;
            back = newNode;
            return;
        }
        back->next = newNode;
        back = newNode;
    }

    void Deque()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node *toDel = front;
        front = front->next;
        delete toDel;
    }

    int Peek()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Queue qu;
    qu.Enque(1);
    qu.Enque(2);
    qu.Enque(3);
    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.isEmpty() << endl;
}
