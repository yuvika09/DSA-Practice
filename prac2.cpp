// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<string>> v;
//         for (int i = 0; i < 3; i++)
//         {
//             vector<string> num;
//             for (int i = 0; i < n; i++)
//             {
//                 string s;
//                 cin >> s;
//                 num.push_back(s);
//             }
//             v.push_back(num);
//         }
//         map<string, int> m;
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 m[v[i][j]]++;
//             }
//         }
//         int matrix[3] = {0};
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (m[v[i][j]] == 1)
//                     matrix[i] += 3;
//                 else if (m[v[i][j]] == 2)
//                     matrix[i] += 1;
//                 else if (m[v[i][j]] == 3)
//                     matrix[i] += 0;
//             }
//         }
//         for (int i = 0; i < 3; i++)
//         {
//             cout << matrix[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int matrix[n][5] = {0};
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            for (int j = 0; j < num; j++)
            {
                int ind;
                cin >> ind;
                matrix[i][ind - 1] = 1;
            }
        }
        int fl = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (matrix[i][k] == 1 || matrix[j][k] == 1)
                        count++;
                    if (count == 5)
                    {
                        fl = 1;
                        break;
                    }
                }
            }
        }
        if (fl == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}