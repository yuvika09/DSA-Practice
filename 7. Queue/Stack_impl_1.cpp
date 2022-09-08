//Implementing queue using stack

// APPROACH 1:
// using 2 stacks -> dequeue costly

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void Enque(int val)
    {
        s1.push(val);
    }
    int Deque()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        if (s2.empty())
        // we check so that if there is any new element it may get pushed to s2
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        // if (s1.empty())
        // {
        //     while (!s2.empty())
        //     {
        //         s1.push(s2.top());
        //         s2.pop();
        //     }
        // }
        return topVal;
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

