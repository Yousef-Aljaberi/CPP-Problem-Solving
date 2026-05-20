#include <iostream>
using namespace std;

// ŞÑÇÁÉ ÑŞã ãæÌÈ ãä ÇáãÓÊÎÏã
int ReadPositiveNumber(string message)
{
    int number = 0;

    do
    {
        cout << message << endl;
        cin >> number;

    } while (number <= 0);

    return number;
}

// ØÈÇÚÉ ÇáäãØ ÇáÑŞãí
void PrintNumberPattern(int number)
{
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }
}

int main()
{
    PrintNumberPattern(
        ReadPositiveNumber("Please enter a positive number:")
    );

    return 0;
}