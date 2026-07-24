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
stDate CalculateVactionDaysReturnDate(stDate DateFrom, short VactionDays)
{
	short WeekEndCounter = 0;
	for (int i = 1; i <= VactionDays; i++)
	{
		if (IsWeekEnd(DateFrom))
		{
			WeekEndCounter++;
		}
		DateFrom = IncreaseDateByOneDay(DateFrom);

	}
	for (int i = 1; i <= WeekEndCounter; i++)
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}
	
	return DateFrom;
}
	
short ReadDaysVaction()
{
	short Days;
	cout << "\nPlease enter vaction days? ";
	cin >> Days;
	return Days;
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
	stDate ReturnDate, DateTo;
	cout << "Vaction Starts:\n";
	ReturnDate = ReadDate();

	short VactionDays = ReadDaysVaction();

	DateTo = CalculateVactionDaysReturnDate(ReturnDate, VactionDays);
	cout << "\n\nReturn Date: " << ShortDayName(DayOfWeekOrder(DateTo)) << ", " 
		<< DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;



	system("pause>0");
	return 0;
}