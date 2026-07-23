#pragma warning(disable : 4996)
#include<iostream>
#include<ctime>
using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
short DayOfWeekOrder(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sunday, 1:Monday ....
	return 	(Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}
stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (Date.Month == 12)
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}
short DayOfWeekOrder(stDate Date)
{
	int a = (14 - Date.Month) / 12;
	int y = Date.Year - a;
	int m = Date.Month + (12 * a) - 2;
	//Gregorian:
	//0:Sunday, 1:Monday ....
	return 	(Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day) : false)) : false);

}
int GetDiffrenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

string ShortDayName(short index)
{

	string arrDaysName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDaysName[index];
}

bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return DayIndex == 5 || DayIndex == 6;
}
bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}
short DaysUntilEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

int DaysUntilEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;
	
	return GetDiffrenceInDays(Date, EndOfMonthDate);
}

int DaysUntilEndOfYear(stDate Date)
{
	stDate EndOfYearsDate;
	EndOfYearsDate.Day = 31;
	EndOfYearsDate.Month = 12;
	EndOfYearsDate.Year = Date.Year;
	
	return GetDiffrenceInDays(Date, EndOfYearsDate);

}

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}
int main()
{
	stDate TodayDate = GetSystemDate();
	string TodayName = ShortDayName(DayOfWeekOrder(TodayDate));
	cout << "\nToday is " << TodayName << " , " << TodayDate.Day << "/" << TodayDate.Month << "/" << TodayDate.Year;

	cout << "\n\n Is it End of week?";

	if (IsEndOfWeek(TodayDate))
	{
		cout << "\n\nYes, it is  end of week";
	}
	else
	{
		cout << "\n\nNo, Not end ofweek ";

	}
	cout << "\n\nIs it weekend?";

	if (IsWeekEnd(TodayDate))
	{
		cout << "\n\nYes, it is a week end";
	}
	else
	{
		cout << "\n\nNo, it is Not a week end";

	}
	cout << "\n \nIs business Day?";

	if (IsBusinessDay(TodayDate))
	{
		cout << "\n\nYes, it is a business day";
	}
	else
	{
		cout << "\n\nNo, it is Not a a business day";

	}
	

	cout << "\nDays until end of week : " << DaysUntilEndOfWeek(TodayDate) << " Day(s)";
	cout << "\nDays until end of month: " << DaysUntilEndOfMonth(TodayDate) << " Day(s)";
	cout << "\nDays until end of Year   : " << DaysUntilEndOfYear(TodayDate) << " Day(s)";






	system("pause>0");
	return  0;
}