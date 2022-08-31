// implementation of stack using array

#include <bits/stdc++.h>
using namespace std;
#define n 100

class Stack
{
private:
    int *arr; // dynamic array
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void Push(int val)
    {
        if (top == n-1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top];
    }

    bool Empty(){
        return top==-1;        //returns 1 when condition is true i.e. top is -1
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
    cout << st.Top() << endl;
    cout << st.Empty() << endl;
    return 0;
}