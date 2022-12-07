// Using inbuilt stack library to create 
//Conversion of infix to postfix expression using stack

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int Precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    int i = 0;
    string postfix = "";
    // using inbuilt stack< > from C++ stack library
    stack<int> s;

    for (int i = 0; i < infix.length(); i++)
    {
        // if operand add to the postfix expression
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            postfix += infix[i];
        }
        // if opening bracket then push the stack
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        // if closing bracket encounted then keep popping from stack until
        // closing a pair opening bracket is not encountered
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // to pop the '(' from the stack
        }
        else
        {
            while (!s.empty() && Precedence(infix[i]) <= Precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix = "((a+(b*c))-d)";
    cout << infixToPostfix(infix);
    return 0;
}