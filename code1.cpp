#include <bits/stdc++.h>
using namespace std;

double ans = 0, num1, num2; // declaring global variables

double operation(int ch)
{
    // taking 2 inputs to perform operations on
    cout << "Enter 1st number : ";
    cin >> num1;
    cout << "Enter 2nd number : ";
    cin >> num2;

    // performing operations
    switch (ch)
    {
    case 1:
        ans = num1 + num2;
        break;
    case 2:
        ans = num1 - num2;
        break;
    case 3:
        ans = num1 / num2;
        break;
    case 4:
        ans = num1 * num2;
    default:
        break;
    }
    return ans;
}

int main()
{
    while (true)
    {
        int ch;
        cout << "1. Addition\n2. Subtraction\n3. Division\n4. Multiplication\nPress 0 to exit....\n\nEnter your choice : ";
        cin >> ch;  //taking input of operation to be performed

        if (ch == 0 || ch > 4)
        {
            cout << "Please choose operations from 1 to 4" << endl;
            break;
        }
        
        operation(ch);
        cout << "Your Answer : " << ans << "\n\n";
    }
    return 0;
}