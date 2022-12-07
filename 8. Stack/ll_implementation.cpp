// Insertion at head in ll is O(1) complex
// so we let head as the top of the stack

#include <bits/stdc++.h>
using namespace std;
#define n 100

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

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }

    void Push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        cout << "Element pushed" << endl;
    }

    void Pop()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
        }
        Node *toDel = head;
        head = toDel->next;
        delete toDel;
        cout << "Element poped" << endl;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        return 0;
    }

    int Top()
    {
        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
        }
        return head->data;
    }
};

int main()
{
    Stack st;
    cout << st.isEmpty()<< endl;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Pop();
    cout << st.Top() << endl;
    cout << st.isEmpty()<< endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    // cout << st.Top() << endl;
    cout << st.isEmpty()<< endl;

    return 0;
}