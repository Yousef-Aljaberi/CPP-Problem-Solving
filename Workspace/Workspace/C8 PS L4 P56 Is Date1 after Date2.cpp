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
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day) : false)) : false);

}
 bool IsDate1EqualDate(stDate Date1, stDate Date2)
 {
	 return ((Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month ? (Date1.Day == Date2.Day) : false) : false);
 }

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate(Date1, Date2));
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
	cout << "Enter Date1: ";
	Date1 = ReadDate();

	cout << "\nEnter Date2: ";
	Date2 = ReadDate();

	if (IsDate1AfterDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is After Date2";
	}
	else
		cout << "\nNo, Date1 is Not After Date2"; 
}