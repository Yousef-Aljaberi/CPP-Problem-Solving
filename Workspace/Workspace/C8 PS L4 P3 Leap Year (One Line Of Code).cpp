#include<iostream>
using namespace std;

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}



int main()
{
	short Year;
	cout << "Enter  Year to check is it Leap Year or not: \n";
	cin >> Year;
	if (IsLeapYear(Year))
		cout << "Yes, The Year [" << Year << "] is Leap." << endl;


	else
		cout << "No, The Year [" << Year << "] is Not Leap." << endl;
}