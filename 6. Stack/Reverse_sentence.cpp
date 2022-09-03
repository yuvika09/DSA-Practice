//Reverse a sentence using stack
//using stack from library(STL) no need for implementing it

#include <bits/stdc++.h>
#include <stack>
using namespace std;

void ReverseSent(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string word;
        while (s[i] != ' ' && i < s.length())
        {
            word = word + s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}

int main()
{
    string s = "hey how u doin";
    ReverseSent(s);
    return 0;
}