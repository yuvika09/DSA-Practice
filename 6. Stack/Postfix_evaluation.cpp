// Taking a prefix expression(string) as input and
// evaluating its answer by using stack
// first element popped is kept in operator2

#include <bits/stdc++.h>
using namespace std;

int postfixEval(string s)
{
    stack<int> st;

    // we traverse from beginning in prefix expression
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    string s = "46+2/5*7+";
    cout << postfixEval(s) << endl;
    return 0;
}