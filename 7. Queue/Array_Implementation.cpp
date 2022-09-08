// Array implementation of Queue

#include <bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{
private:
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];       //dynamic array
        front = -1;
        back = -1;
    }
    void Enque(int val)
    {
        if (front == n - 1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front++;
        }
        back++;
        arr[back] = val;
    }
    void Deque()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    int Peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue qu;
    qu.Enque(1);
    qu.Enque(2);
    qu.Enque(3);
    qu.Enque(4);

    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.Peek() << endl;
    qu.Deque();
    cout << qu.Peek() << endl;
    qu.Deque();
    return 0;
}
