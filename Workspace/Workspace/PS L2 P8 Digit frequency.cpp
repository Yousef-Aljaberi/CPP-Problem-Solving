#include <iostream>
using namespace std;
int readPostiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;


	} while (Number < 0);

	return Number;
}

int CountDigitFrequency(int number1, short DigitToCheck)
{

	int remainder = 0, count = 0;
	while (number1 > 0)
	{
		remainder = number1 % 10;
		number1 = number1 / 10;
		if (remainder == DigitToCheck)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int number1 = readPostiveNumber("Please enter a  positive number");
	short DigitToCheck = readPostiveNumber("Please enter the number to search");
	cout << "Digit: " << DigitToCheck << " Frequency is " << CountDigitFrequency(number1, DigitToCheck) << " Time(s)." << endl;
}