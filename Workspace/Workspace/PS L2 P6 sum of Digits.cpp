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

int sumOfDigits(int Number)
{
	int Sum = 0, Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Sum += Remainder;

	}

	return Sum;
}
void printResult(int number)
{
	cout << "the sum of results is " << number << " " << endl;
}
int main()
{
	//printResult(sumOfDigits(readPostiveNumber("Please enter a positive number")));
	// or 
	cout << "sum of digits is " << sumOfDigits(readPostiveNumber("enter a number "));

}