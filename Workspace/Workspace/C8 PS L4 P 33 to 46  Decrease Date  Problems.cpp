#include<iostream>
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

	short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
}

stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if ((Date.Month == 1))
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDay(stDate Date,int Days)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeek(stDate Date, int Weeks)
{
	for (int i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
		
	}
	else
	{
		Date.Month--;
	}
	//ÅÐÇ ßÇä ÚÏÏ ÇáÃíÇã Ýí ÇáÔåÑ ÈÚÏ ÇáÓÇÈÞ ÃßÈÑ ãä ÚÏÏ ÇáÃíÇã Ýí ÇáÔåÑ ÇáÍÇáí
	short NumberOfDaysInCurrnMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberOfDaysInCurrnMonth)
	{
		Date.Day = NumberOfDaysInCurrnMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonth(stDate Date,int Months)
{
	for (int i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}
stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;

	return Date;
}
stDate DecreaseDateByXYear(stDate Date, int Years)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByXYearFaster(stDate Date, int Years)
{
	Date.Year -= Years;
	if (IsLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
	{
		Date.Day = 28;
	}

	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}
stDate DecreaseDateByXDecade(stDate Date, int Decades)
{
	for (int i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date,int Decades)
{
	Date.Year -= Decades * 10;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
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
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

int main()
{
	stDate Date1 = ReadFullDate();
	 
	cout << "\nDate After \n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDay(Date1,10);
	cout << "\n02-Subtracting 10 days is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeek(Date1,10);
	cout << "\n04-Subtracting 10 weeks is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonth(Date1,5);
	cout << "\n06-Subtracting 5 months is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYear(Date1,10);
	cout << "\n08-Subtracting 10 year is: ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Subtracting 10 year is (faster): ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one decade is : ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecade(Date1,10);
	cout << "\n11-Subtracting 10 decade is : ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadeFaster(Date1, 10);
	cout << "\n12-Subtracting 10 decade is (faster) : ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting one century is  : ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting one Millennium is  : ";
	cout << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;




	system("pause>0");
	return 0;

}