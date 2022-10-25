// print the previous nearest smaller element in the array
// else print -1

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void prevSmall(int a[], int size)
{
    stack<int> s;
    for (int i = 0; i < size; i++)
    {
        while (!s.empty() && s.top() >= a[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << -1 << " ";
        }
        else
        {
            cout << s.top() << " ";
        }
        s.push(a[i]);
    }
}

// void prevSmall2(int a[], int size)
// {
//     stack<pair<int, int>> s;
//     vector<int> v;
//     for (int i = 0; i < size; i++)
//     {
//         while (!s.empty() && s.top().second >= a[i])
//         {
//             s.pop();
//         }
//         if (s.empty())
//         {
//             // cout << -1 << " ";
//             v[i] = -1;
//         }
//         else
//         {
//             // cout << s.top() << " ";
//             v[i] = s.top().first;
//         }
//         pair<int, int> p;
//         p = make_pair(i, a[i]);
//         s.push(p);
//     }
//     for (auto i : v)
//     {
//         cout << i;
//     }
// }

int main()
{
    int a[] = {4, 2, 1, 5, 6, 3, 2, 4, 2};
    int size = 9;
    prevSmall(a, size);
    return 0;
}