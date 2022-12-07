// Taking a prefix expression(string) as input and
// evaluating its answer by using stack
//first element popped is kept in operator1

#include <bits/stdc++.h>
using namespace std;

int prefixEval(string s)
{
    stack<int> st;

    // we traverse from end in prefix expression
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
    string s = "+*423";
    cout << prefixEval(s) << endl;
    return 0;
}