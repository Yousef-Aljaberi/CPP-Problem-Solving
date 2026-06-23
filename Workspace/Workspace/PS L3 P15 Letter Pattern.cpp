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
void printLetterPattern(int Number)
{
	for (int i = 65; i <= Number + 65 - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}

}
int main()
{
	printLetterPattern(readPositiveNumber("enter a positive Number"));
}