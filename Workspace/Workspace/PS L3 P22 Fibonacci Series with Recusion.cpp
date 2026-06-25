#include<iostream>
using namespace std;

void PrintFibonacciUsingRecursion(int Prev1, int Prev2, int Number)
{

	if (Number > 0)
	{
		int FibNumber;
		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "  ";
		Prev1 = Prev2;
		Prev2 = FibNumber;

		PrintFibonacciUsingRecursion(Prev1, Prev2, Number - 1);
	}
	
}


int main()
{
	PrintFibonacciUsingRecursion(0,1,10);
}

