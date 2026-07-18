#include<iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
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
	stDate Date1, Date2;
	Date1 = ReadDate();
	cout << "\n";
	Date2 = ReadDate();
	if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is Equal than Date2\n";
	}
	else
		cout << "No, Date1 is not Equal than Date2\n";
}
