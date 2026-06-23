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
void printDigitFrequency(int Number)
{
	for (int i = 0; i < 10; i++)
	{
		short DigitFrequency = CountDigitFrequency(Number, i);
		if (DigitFrequency > 0)
		{
			cout << "the Number: " << i << " Frequnecy is " << DigitFrequency << " Time(s).\n";
		}
	}
}
int main()
{
	printDigitFrequency(readPostiveNumber("Please enter a positive number"));
}