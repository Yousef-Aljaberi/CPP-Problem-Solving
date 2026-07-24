#include<iostream>
using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};


short DayOfWeekOrder(stDate Date)
{
	int a = (14 - Date.Month) / 12;
	int y = Date.Year - a;
	int m = Date.Month + (12 * a) - 2;
	//Gregorian:
	//0:Sunday, 1:Monday ....
	return 	(Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string ShortDayName(short index)
{

	string arrDaysName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDaysName[index];           
}
bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day) : false)) : false);

}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
		return 0;

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
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
bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return DayIndex == 5 || DayIndex == 6;
}
bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}
short CalculateVactionDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;
	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			DaysCount++;
		}
		DateFrom = IncreaseDateByOneDay(DateFrom);
		
	}
	return DaysCount;
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
stDate ReadDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
int main()
{
	stDate DateFrom, DateTo;
	cout << "Vaction Starts:\n";
	DateFrom = ReadDate();

	cout << "\n\nVaction Ends:\n";
	DateTo = ReadDate();

	string StratDayName = ShortDayName(DayOfWeekOrder(DateFrom));
	string EndDayName = ShortDayName(DayOfWeekOrder(DateTo));
	
	cout << "\nVaction From: " << StratDayName << ", " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year;
	cout << "\nVaction To: " << EndDayName << ", " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;
	cout << "\n\nActual Vaction Days is/are: " << CalculateVactionDays(DateFrom, DateTo);

	system("pause>0");
	return 0;
}