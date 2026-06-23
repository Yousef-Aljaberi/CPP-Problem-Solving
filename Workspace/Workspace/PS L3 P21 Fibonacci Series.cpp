#include<iostream>
using namespace std;




void PrintFibonacciUsingLoop(int Number)
{
	int Prev1 = 1, Prev2 = 1; int Temp = 0;
	cout << Prev1 << "	" << Prev2 << "	  ";
	for (int i = 0; i < Number; i++)
	{
		Temp = Prev1 + Prev2;
		cout << Temp << "	 ";
		Prev1 = Prev2;
		Prev2 = Temp;

	}
}






int main()
{
	PrintFibonacciUsingLoop(9);
}