#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
short GetIndexOfDay(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sunday, 1:Monday ....
	return 	(Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}


bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMoth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
string MonthShortName(short Month)
{
	if (Month > 12 || Month < 1)
		return "";
	string arrShortMonthName[12] = { "Jan","Feb","Mar","Ipr","May","Jun","jul","Aug","Sep","Oct","Nov","Dec" };
	return arrShortMonthName[Month - 1];
}


short ReadYear()
{
	int Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}

void PrintMonthCalendar(int Year, short Month)
{
	short NumberOfDayInMonth = NumberOfDaysInMoth(Year, Month);

	//index of the day 0 to 6
	short IndexOfDay = GetIndexOfDay(Year, Month, 1);


	//print currn month name
	printf("\n---------------------------%s---------------------------\n\n", MonthShortName(Month).c_str());

	//print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	int i;
	//print appropriate space
	for (i = 0; i < IndexOfDay; i++)
		printf("     ");


	for (int j = 1; j <= NumberOfDayInMonth; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}

	}
	cout << "\n-------------------------------------------------------\n";
}

void PrintYearCalender(short Year)
{
	cout << "\n-------------------------------------------------------\n";
	cout << "\t\t\t Calender - " << Year;
	cout << "\n-------------------------------------------------------\n";

	for (short i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(Year, i);
	}
}

int main()
{
	short Year = ReadYear();
	PrintYearCalender(Year);
}