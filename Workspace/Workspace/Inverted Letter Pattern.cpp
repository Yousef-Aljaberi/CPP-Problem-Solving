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

void PrintInvertedLetterPattern(int Number)
{
	for (int i = Number; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(64 + i);//convert numbers to chars 
		}

		cout << "\n";
	}
}
int main()
{
	PrintInvertedLetterPattern(readPositiveNumber("please enter a positive Number"));
}