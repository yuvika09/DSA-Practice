#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeInt(vector<vector<int>> v)
{
    vector<vector<int>> ansInt;
    if (v.size() == 0)
    {
        return ansInt;
    }
    sort(v.begin(), v.end());
    vector<int> tempInt = v[0];
    for (auto i : v)
    {
        if (i[0] <= tempInt[1])
        {
            tempInt[1] = max(tempInt[1], i[1]);
        }
        else
        {
            ansInt.push_back(tempInt);
            tempInt = i;
        }
    }
    ansInt.push_back(tempInt);
    return ansInt;
}

int main()
{
    vector<vector<int>> v{{1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}, {19, 20}};
    vector<vector<int>> vv = mergeInt(v);
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[0].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}