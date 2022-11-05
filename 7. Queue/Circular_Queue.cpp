// Implementation of circular queue using array

#include <bits/stdc++.h>
#define n 5
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;

public:
    CircularQueue()
    {
        arr = new int[n]; // dynamic array
        front = -1;
        rear = -1;
    }
    void Enque(int val)
    {
        if ((rear + 1) % n == front)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % n;
        arr[rear] = val;
    }
    int Deque()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int res = arr[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
        return res;
    }
    void Display()
    {
        if (front == -1)
        {
            cout << "Queue Underflow" << endl;
            return ;
        }
        else{
            for (int i = front; i <= rear; i=(i+1)%n)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    CircularQueue qu;
    qu.Enque(1);
    qu.Enque(2);
    qu.Enque(3);
    qu.Enque(4);
    // cout << qu.Peek() << endl;
    qu.Deque();
    // cout << qu.Peek() << endl;
    // qu.Deque();
    // cout << qu.Peek() << endl;
    // qu.Deque();
    // cout << qu.Peek() << endl;
    qu.Deque();
    qu.Display();
    return 0;
}