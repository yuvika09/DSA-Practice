// Conversion of infix to prefix expression using stack
// using inbuild stack stl and algorithm lib for reversing the string

#include <iostream>
#include <stack>
#include <algorithm>
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

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    stack<char> s;
    string prefix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        // if operand add to the prefix expression
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
        {
            prefix += infix[i];
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
            while (!s.empty() && s.top() != '(')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop(); // to pop the '(' from the stack
        }
        else
        {
            while (!s.empty() && Precedence(infix[i]) <= Precedence(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix = "((a-b/c)*(a/k-l))";
    cout << infixToPrefix(infix);
    return 0;
}