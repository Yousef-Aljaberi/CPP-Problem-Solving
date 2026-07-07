#include<iostream>
using namespace std;
bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMoth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 30) : NumberOfDays[Month - 1];
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

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInMoth(Year, Month);

	
	cout << endl;


}