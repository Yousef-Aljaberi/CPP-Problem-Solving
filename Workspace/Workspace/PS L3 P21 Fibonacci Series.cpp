#include<iostream>
using namespace std;




void PrintFibonacciUsingLoop(int Number)
{
	int Prev1 = 0, Prev2 = 1; int FebNumber = 0;
	cout << "1  ";
	for (int i = 0; i < Number; i++)
	{
		FebNumber = Prev1 + Prev2;
		cout << FebNumber << "	 ";
		Prev1 = Prev2;
		Prev2 = FebNumber;

	}
}






int main()
{
	PrintFibonacciUsingLoop(9);
}