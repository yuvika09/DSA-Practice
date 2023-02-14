
//HARD

#include <bits/stdc++.h>
using namespace std;

// Approach2: Without using space
void mergeAr1(vector<int> &a1, vector<int> &a2)
{
    for (int i = 0; i < a1.size(); i++)
    {
        if (a1[i] > a2[0])
        {
            swap(a1[i], a2[0]);
            int j = 1;
            while (a2[j - 1] > a2[j] && j < a2.size())
            {
                swap(a2[j - 1], a2[j]);
                j++;
            }
        }
    }
}

// Approach3: Gap Method
void mergeAr(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size(), m = a2.size();
    int gap = ceil((float)(n + m) / 2);
    while (gap >= 1)
    {
        int i = 0, j = gap;
        while (j < (n + m))
        {
            if (j < n && a1[i] > a1[j])
            {
                swap(a1[i], a1[j]);
            }
            else if (j >= n && i < n && a1[i] > a2[j - n])
            {
                swap(a1[i], a2[j - n]);
            }
            else if (j >= n && i >= n && a2[i - n] > a2[j - n])
            {
                swap(a2[i - n], a2[j - n]);
            }
            j++;
            i++;
        }
        gap /= 2;
    }
}

int main()
{
    vector<int> a1{1, 4, 7, 8, 10};
    vector<int> a2{2, 3, 9};
    mergeAr(a1, a2);
    for (auto i : a1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : a2)
    {
        cout << i << " ";
    }
    return 0;
}