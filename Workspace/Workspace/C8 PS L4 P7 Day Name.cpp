#include<iostream>
using namespace std;
short ReadDay()
{
	int Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	int Year;
	cout << "\nPlease enter a Month? ";
	cin >> Year;
	return Year;
}

short ReadYear()
{
	int Year;
	cout << "\nPlease enter a year? ";
	cin >> Year;
	return Year;
}

short IndexOfDay(short Year, short Month, short Day)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	//Gregorian:
	//0:Sunday, 1:Monday ....
	return 	(Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

string DayName(short index)
{
	
	string arrDaysName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDaysName[index];
}


int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
	short index = IndexOfDay(Year, Month, Day);
	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;
	cout << "\nDay Order :" << index;
	cout << "\nDay Name  :" << DayName(index);

}