#include<iostream>
using namespace std;
bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}
	// if you reach here then its 30 days 
	return 30;
	
}
short NumberOfHoursInMonth(short Year,short Month)
{
	return NumberOfDaysInMonth(Year,Month) * 24;
}
int NumberOfMinutsInMonth(short Year,short Month)
{
	return NumberOfHoursInMonth(Year,Month) * 60;
}
int NumberOfSecendsInMonth(int Year, short Month)
{
	return NumberOfMinutsInMonth(Year, Month) * 60;
}

short ReadMonth()
{
	int Year;
	cout << "\nPlease enter a Month to check? ";
	cin >> Year;
	return Year;
}

short ReadYear()
{
	int Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMonth(Year,Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInMonth(Year,Month);
	cout << "\nNumber of Minuts  in Month [" << Month << "] is " << NumberOfMinutsInMonth(Year,Month);
	cout << "\nNumber of Secends in Month [" << Month << "] is " << NumberOfSecendsInMonth(Year,Month);

	cout << endl;


}