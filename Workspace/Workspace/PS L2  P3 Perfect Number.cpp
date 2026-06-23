#include<iostream>
using namespace std;

int readPositveNumber(string Messege)
{
	int Number = 0;
	do
	{
		cout << Messege << endl;
		cin >> Number;

	} while (Number < 0);
	return Number;
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

void PrintPerfectNumber(int Number)
{

	if (IsPerfectNumber(Number))
		cout << "The Number: " << Number << " is Perfect" << endl;

	else
		cout << "The Number: " << Number << " is Not Perfect" << endl;

}

int main()
{
	PrintPerfectNumber(readPositveNumber("please enter a positve number"));
}