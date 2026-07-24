#include<iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
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
	cout << "Enter Date1;";
	Date1 = ReadDate();
	cout << "\nEnter Date2";
	Date2 = ReadDate();

	cout << "\n\nCompare Result is =" << CompareDate(Date1, Date2);

	system("pause>0");
	return 0;
}