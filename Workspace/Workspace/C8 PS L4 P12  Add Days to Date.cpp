#include<iostream>
using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMoth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 30) : NumberOfDays[Month - 1];
}


struct stDate
{
	short Year;
	short Month;
	short Day;
};
stDate AddDaysToDate(short Day,short Month,short Year,int DaysToAdd)
{
	stDate Date;
	short MonthDays = 0;
	short NumberOfDaysInYear = IsLeapYear(Year) ? 366 : 365;

	Date.Year = Year;
	Date.Month = Month;
	Date.Day = Day;
	while (true)
	{
		MonthDays = NumberOfDaysInMoth(Date.Year, Date.Month);
		if ( DaysToAdd> NumberOfDaysInYear)
		{
			DaysToAdd -= NumberOfDaysInYear;
			Date.Year++;
		    NumberOfDaysInYear = IsLeapYear(Year) ? 366 : 365;
		}

		else if (DaysToAdd > MonthDays)
		{
			DaysToAdd -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Year++;
				Date.Month -=12;
			}
		}

		else
		{
			Date.Day += DaysToAdd;
			short MonthDay = NumberOfDaysInMoth(Date.Year, Date.Month);
			if (Date.Day > MonthDay)
			{
				Date.Day -= MonthDay;
				Date.Month++;
			}
			break;
		}
	}
	return Date;
}
int ReadDaysToAdd()
{
	int DaysToAdd;
	cout << "\nPlease enter days to add? ";
	cin >> DaysToAdd;
	return DaysToAdd;
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
	short DaysToAdd = ReadDaysToAdd();



	stDate Date = AddDaysToDate(Day,Month, Year,DaysToAdd);

	cout << "\nDate after adding  [" << DaysToAdd << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}