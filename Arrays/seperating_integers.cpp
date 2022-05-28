//bringing all the negative elements in left and positive in right of the array.

#include <bits/stdc++.h>
using namespace std;

int *seperate(int arr[], int size){
    int i = 0, j = size-1;
    while(i<j){
        while(arr[i]<0)
            i++;
        while(arr[j]>=0)
            j--;
        if(i<j)
            swap(arr[i], arr[j]);
    }
    return arr;
}
int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    seperate(arr, a);  
    for (int i = 0; i < a; i++)
        cout << arr[i] << " ";
    return 0;
}