#include <bits/stdc++.h>
#define ll long long
using namespace std;

void searchInfinite(int arr[], int key)
{
    int low = 0, high = 1;
    while (arr[high] < key)
    {
        low = high;
        high = 2 * high;
    }
    return binSearch(arr, key, high, low);
}

int main()
{
    // an infinte array given with a key to find the number
    return 0;
}