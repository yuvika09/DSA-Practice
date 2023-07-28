// Task 1:
// Number guessing game:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0)); // add the random number generator

    int randNum = rand() % 10 + 1; // Generate a random number between 1 and 10

    int guess, attempts = 0; // add variable to store values

    cout << "Welcome to the Number Guessing Game! " << endl;
    cout << endl;

    do
    {
        cout << "Enter Your guess (between 1 and 10): " << endl;
        cin >> guess;

        // check if the guess is too high or too low
        if (guess > randNum)
        {
            cout << "Oops Sorry!! Try a smaller value. " << endl;
        }
        else if (guess < randNum)
        {
            cout << "Oops Sorry!! Try a larger value. " << endl;
        }

        attempts++; //keep track of the no. of attempts

    } while (guess != randNum);

    cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
    cout << endl;

    return 0;
}