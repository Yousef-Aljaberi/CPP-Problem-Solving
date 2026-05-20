#include <iostream>
#include <string>

using namespace std;

// Function to read a positive integer from the user
int readPositiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0); // Keep looping if the number is zero or negative

    return number;
}

// Function to print the inverted number pattern

void printInvertedPattern(int number)
{
    for (int i = number; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        // Move to the next line after finishing each row
        cout << endl;
    }
}

int main()
{
    printInvertedPattern(readPositiveNumber("Please enter a positive number:"));

    return 0;
}