//Implementing stack using queue

// APPROACH 1:
// Making push costly

#include <bits/stdc++.h>
using namespace std;
// #define N 100

class Stack
{
private:
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }
    void Push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void Pop()
    {
        q1.pop();
        N--;
    }

    int Top()
    {
        return q1.front();
    }

    int Size()
    {
        return N;
    }
};

int main()
{
    Stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Top() << endl;
    st.Pop();
    cout << st.Size() << endl;
    return 0;
}
