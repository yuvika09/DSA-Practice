#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, flag = 0;
        cin >> n;
        int matrix[n][5];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                matrix[i][j] = 0;
            }
        }
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            vector<int> temp;
            for (int i = 0; i < x; i++)
            {
                int l;
                cin >> l;
                temp.push_back(l);
            }
            v.push_back(temp);
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int c = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (v[i][k] == 1 || v[j][k] == 1)
                    {
                        c++;
                    }
                    if (c == 5)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        }
    return 0;
}