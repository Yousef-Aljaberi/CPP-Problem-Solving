#include<iostream>
using namespace std;
struct stDate
{
	short Year;
	short Month;
	short Day;
};
struct stPeriod
{
	stDate StratDate;
	stDate EndDate;
};

enum enDateCompare { Befor = -1, Equal = 0, After = 1 };

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day) : false)) : false);

}
bool IsDate1EqualDate(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
}


short CompareDate(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Befor;
	else if (IsDate1EqualDate(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}
bool IsOverlapPeriod(stPeriod Period1, stPeriod Period2)
{
	if (CompareDate(Period2.EndDate, Period1.StratDate) == enDateCompare::Befor
		||
		CompareDate(Period2.StratDate, Period1.EndDate) == enDateCompare::After
		)
		return false;
	
	return true;
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
short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;

	return Day;
}

stDate ReadDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;

}
stPeriod ReadFullPeriod()
{
	stPeriod Period;
	cout << "\nEnter Start Date:";
	Period.StratDate = ReadDate();
	cout << "\n\nEnter End Date:";
	Period.EndDate = ReadDate();
	return Period;
}

int main()
{
	stPeriod Period1, Period2;
	cout << "Enter Period1";
	Period1 = ReadFullPeriod();
	cout << "\n\nEnter Period2";
	Period2 = ReadFullPeriod();

	if (IsOverlapPeriod(Period1, Period2))
	{
		cout << "\n\nYes, Periods Overlap";
	}
	else
		cout << "\n\nNo, Periods is Not Overlap";

}