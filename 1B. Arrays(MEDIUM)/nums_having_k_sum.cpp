// find a pair with sum k(a+b=k). array not having duplicate elements

#include <bits/stdc++.h>
using namespace std;

void without_sorting(int arr[], int a, int k)
{
    int hash[20] = {0};
    for (int i = 0; i <= 20; i++)
    {
        if (hash[k - arr[i]] != 0)
            cout << k - arr[i] << " and " << arr[i] << endl;
        hash[arr[i]]++;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << hash[i] << " " ;
    }
    
}

void with_sorting(int arr[], int a, int k)
{
    sort(arr, arr + a);
    for (int i = 0, j = a - 1; i < j;)
    {
        if(arr[i] + arr[j] == k){
            cout << k - arr[i] << " and " << arr[i] << endl;
            i++; j--;
        }
        else if(arr[i] + arr[j] < k)
            i++;
        else  
            j++;
    }
}

int main()
{
    int a, k;
    cin >> a >> k;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    // without_sorting(arr, a, k);
    with_sorting(arr, a, k);
    return 0;
}