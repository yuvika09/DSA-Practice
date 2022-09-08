//Implementing queue using stack

// APPROACH 2:
// using function call stack(recursive fn)

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;

public:
    void Enque(int val)
    {
        s1.push(val);
    }
    int Deque()
    {
        if (s1.empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }
        int item = Deque();
        s1.push(x);
        return item;
    }
};

int main()
{
    Queue q;
    q.Enque(1);
    q.Enque(99);
    q.Enque(3);
    cout << q.Deque() << endl;
    q.Enque(88);
    cout << q.Deque() << endl;
    cout << q.Deque() << endl;
    cout << q.Deque() << endl;
    return 0;
}