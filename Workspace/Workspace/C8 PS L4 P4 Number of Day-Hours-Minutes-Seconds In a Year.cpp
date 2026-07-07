#include<iostream>
using namespace std;

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


int NumberOfDaysInYear(int Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHoursInYear(int Year)
{
	return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutsInYear(int Year)
{
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecendsInYear(int Year)
{
	return NumberOfMinutsInYear(Year) * 60;
}
short ReadYear()
{
	int Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}


int  main()
{
	short Year = ReadYear();
	

		cout << "\nNumber of Days    in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
		cout << "\nNumber of Hours   in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
		cout << "\nNumber of Minuts  in Year [" << Year << "] is " << NumberOfMinutsInYear(Year);
		cout << "\nNumber of Secends in Year [" << Year << "] is " << NumberOfSecendsInYear(Year);

		cout << endl;

}