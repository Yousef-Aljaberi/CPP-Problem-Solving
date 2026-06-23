#include<iostream>
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

int reverseNumber(int Number)
{
	int number2 = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		number2 = number2 * 10 + Remainder;

	}

	return number2;
}
int main()
{
	cout << reverseNumber(readPostiveNumber("enter a number"));
}