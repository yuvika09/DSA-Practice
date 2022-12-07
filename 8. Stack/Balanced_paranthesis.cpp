// checking if the given paranthesis are balanced or not using stack

#include <iostream>
#include <stack>
using namespace std;

// APPROACH 1
bool isOpening(char c)
{
    if (c == '(' || c == '[' || c == '{')
    {
        return true;
    }
    return false;
}
bool isMatch(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}
bool isValid1(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        char curr = str[i];
        if (isOpening(curr))
        {
            s.push(curr);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else if (!isMatch(s.top(), curr))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return (s.empty());
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
    cout << isValid1(s) << endl;
    return 0;
}