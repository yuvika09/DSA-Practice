// checking if the given paranthesis are balanced or not using stack

#include <iostream>
#include <stack>
using namespace std;

// APPROACH 1

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty()) // i/p == {
            {
                return false;
            }
            if (s[i] == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (s[i] == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (s[i] == ']' && st.top() == '[')
            {
                st.pop();
            }
            else // i/p == }
            {
                return false;
            }
        }
    }
    if (st.size() == 0)
    {
        return true;
    }
    return false;
}

// APPROACH 2
bool isValid2(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}

int main()
{
    string s = "{[()]}";
    cout << isValid2(s) << endl;
    return 0;
}