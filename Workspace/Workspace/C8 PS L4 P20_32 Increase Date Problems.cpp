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

stDate IncreaseDateByXDays(stDate Date, int NumberOfDayes)
{
	
	for (int i = 1; i <= NumberOfDayes; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, int NumberOfWeeks)
{
	for (int i = 1; i <= NumberOfWeeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDayInCurrntMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (NumberOfDayInCurrntMonth > Date.Day)
	{
		Date.Day = NumberOfDayInCurrntMonth;
	}
	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int NumberOfMonths)
{
	for (int i = 1; i <= NumberOfMonths; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByXYears(stDate Date, int NumberOfYears)
{
	for (int i = 1; i <= NumberOfYears; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int NumberOfYears)
{
	Date.Year += NumberOfYears;
	return Date;
}




stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;

}
stDate IncreaseDateByXDecade(stDate Date,int NumberOfDecades)
{
	for (int i = 1; i <= NumberOfDecades; i++)
	{
		Date = IncreaseDateByOneDecade(Date);

	}
	return Date;
}

stDate IncreaseDateByXDecadeFaster(stDate Date, int NumberOfDecades)
{
	Date.Year += NumberOfDecades * 10;

	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}

void PrintDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
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
	stDate Date;
	Date = ReadDate();

	Date = IncreaseDateByOneDay(Date);

	cout << "\n01-Adding one day is  : "; 
	PrintDate(Date);
	//adding 10 days
	Date = IncreaseDateByXDays(Date, 10);
	cout << "\n02-Adding 10 days is   : ";
	PrintDate(Date);
	
	//Adding One Week
	Date = IncreaseDateByOneWeek(Date);
	cout << "\n03-Adding one week is  : ";
	PrintDate(Date);

	//Adding x weeks
	Date = IncreaseDateByXWeeks(Date, 10);
	cout << "\n04-Adding 10 weeks is  : ";
	PrintDate(Date);

	//Adding one month
	Date = IncreaseDateByOneMonth(Date);
	cout << "\n05-Adding one month is : ";
	PrintDate(Date);

	//Adding x month
	Date = IncreaseDateByXMonths(Date,5);
	cout << "\n06-Adding 5 Months is  : ";
	PrintDate(Date);

	//Adding one year
	Date = IncreaseDateByOneYear(Date);
	cout << "\n07-Adding one year is  : ";
	PrintDate(Date);

	//Adding x year
	Date = IncreaseDateByXYears(Date, 10);
	cout << "\n08-Adding 10 year is  : ";
	PrintDate(Date);


	//Adding x year (faster)
	Date = IncreaseDateByXYearsFaster(Date, 10);
	cout << "\n09-Adding 10 year  (faster) is: ";
	PrintDate(Date);

	//Adding one decade(10 Years)
	Date = IncreaseDateByOneDecade(Date);
	cout << "\n010-Adding one Decade  : ";
	PrintDate(Date);

	//Adding 10 decades 
	Date = IncreaseDateByXDecade(Date,10);
	cout << "\n011-Adding 10 Decade  : ";
	PrintDate(Date);

	//Adding 10 decades (Faster)
	Date = IncreaseDateByXDecadeFaster(Date, 10);
	cout << "\n012-Adding 10 Decade (faster) : ";
	PrintDate(Date);

	//Adding one Century (100Years)
	Date = IncreaseDateByOneCentury(Date);
	cout << "\n013-Adding one Century   : ";
	PrintDate(Date);

	//Adding one Millennium(1000Years)
	Date = IncreaseDateByOneMillennium(Date);
	cout << "\n014-Adding one Millennium   : ";
	PrintDate(Date);



	system("pause>0");
	return 0;
}