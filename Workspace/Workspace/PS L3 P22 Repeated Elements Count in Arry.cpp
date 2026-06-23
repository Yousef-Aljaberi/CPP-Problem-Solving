#include<iostream>
using namespace std;
int readNumber(string message)
{
	int Number = 0;
	cout << message << endl;
	cin >> Number;
	return Number;
}
void ReadArry(int Arry[100], int& arryLenght)
{
	arryLenght = readNumber("enter the number of arry elements");

	for (int i = 0; i < arryLenght; i++)
	{
		cout << "Element [" << i + 1 << "]:";
		cin >> Arry[i];
	}
}
void PrintArry(int arry[100], int arryLenght)
{
	cout << "the original arry is: ";
	for (int i = 0; i < arryLenght; i++)
	{
		cout << arry[i] << "\t";
	}

}
int timesRepeated(int Arry[], int arryLenght, int NumberToCheck)
{
	int count = 0;

	for (int i = 0; i < arryLenght; i++)
	{
		if (Arry[i] == NumberToCheck)
			count++;

	}
	return count;

}


int main()
{
	int Arry[100], arryLenght, NumberToCheck;
	ReadArry(Arry, arryLenght);
	NumberToCheck = readNumber("enter the number you want to check");
	PrintArry(Arry, arryLenght);


	cout << "\nThe Number: " << NumberToCheck << " has rpeated " << timesRepeated(Arry, arryLenght, NumberToCheck) << " Time(s)." << endl;

}