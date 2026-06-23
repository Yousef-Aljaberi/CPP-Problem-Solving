#include <iostream>
using namespace std;

int readPositiveNumber(string s)
{
	int number = 0;
	do
	{
		cout << s << endl;
		cin >> number;
	} while (number <= 0);
	return number;
}

bool IsPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}
	return Number == Sum;
}

void printPerfectNumbers(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (IsPerfectNumber(i))
		{
			cout << i << endl;
		}
	}
}

int main()
{
	printPerfectNumbers(readPositiveNumber("please enter a positive number"));
}