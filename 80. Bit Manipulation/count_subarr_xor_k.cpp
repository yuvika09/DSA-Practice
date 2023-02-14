//MEDIUM
//Find the total number of subarrays having bitwise XOR of all elements equal to B.

#include <bits/stdc++.h>
using namespace std;

int countXor(vector<int> a, int k)
{
    int count = 0;
    int pXor = 0;
    unordered_map<int, int> freq;
    for (int i = 0; i < a.size(); i++)
    {
        pXor = pXor ^ a[i];
        if (pXor == k)
        {
            count++;
        }
        int y = pXor ^ k;
        if (freq.find(y) != freq.end())
        {
            count += freq[y];
        }
        freq[pXor]++;
    }
    return count;
}

int main()
{
    vector<int> v{4, 2, 2, 6, 4};
    int k = 6;
    cout << countXor(v, k);
    return 0;
}