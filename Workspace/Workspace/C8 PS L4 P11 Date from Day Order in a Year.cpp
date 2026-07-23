#include<iostream>
using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDayFromBeginingOfYear(short Year, short Month, short Day)
{
	short NumberOfDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		NumberOfDays += NumberOfDaysInMonth(Year, i);
	}
	NumberOfDays += Day;

	return NumberOfDays;
}

struct stDate
{
	short Year;
	short Month;
	short Day;
};
stDate GetDateFromDayOrderInYear(short DateOrderInYear,int Year)
{
	stDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}

		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
}
short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month? ";
		cin >> Month;
	} while (Month > 12 || Month < 1);
	return Month;
}

int ReadYear()
{
	int Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();

	short DayOrderInYear = NumberOfDayFromBeginingOfYear(Year, Month, Day);

	cout << "\nNumber of days from the begining is: " << DayOrderInYear;

	stDate Date = GetDateFromDayOrderInYear(DayOrderInYear,Year);

	cout << "\nDate for [" << DayOrderInYear << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}