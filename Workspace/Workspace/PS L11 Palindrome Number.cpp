#include<iostream>
using namespace std;
int readPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}
int ReversedNumber(int Number)
{
	int Remainder = 0, Number2 = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;


	}
	return Number2;

}

void CheckePalindromeNume(int number1)
{
	int reversedNumber = ReversedNumber(number1);
	if (number1 == reversedNumber)
	{
		cout << "Yes, it is a Palindrom Number" << endl;
	}
	else
		cout << "No, it is NOT a palindrome number " << endl;
}
int main()
{
	CheckePalindromeNume(readPositiveNumber("Please enter a positive Number"));
}