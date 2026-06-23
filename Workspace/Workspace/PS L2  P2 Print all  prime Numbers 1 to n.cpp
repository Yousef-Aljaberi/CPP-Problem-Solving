#include<iostream>
using namespace std;
enum enPrimeNotPime { Prime = 1, NotPrime = 2 };
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

enPrimeNotPime CheckPrimeNotPrim(int Number)
{
	int M = round(Number / 2);
	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPime::NotPrime;

	}
	return enPrimeNotPime::Prime;
}
void PrintPrimeFrom1ToN(int Number)
{
	for (int i = 3; i <= Number; i++)
	{
		if (CheckPrimeNotPrim(i) == enPrimeNotPime::Prime)
		{
			cout << "the Number: " << i << " is Prime" << endl;
		}
	}
}
int main()
{
	PrintPrimeFrom1ToN(readPostiveNumber("Please enter a positve Number"));
}