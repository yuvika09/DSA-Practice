#include <iostream>
using namespace std;

void printWave(int arr[][4], int totalR, int totalC)
{
    for (int col = 0; col < totalC; col++)
    {
        if (col & 1)
        {
            for (int row = totalR - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (int row = 0; row < totalR; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};

    printWave(arr, 3, 4);
    return 0;
}