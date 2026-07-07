#include<iostream>
using namespace std;

bool IsLeapYear(int Year)
{
	if (Year % 400 == 0)
		return true;
	/*else if (Year % 4 == 0 && Year % 100 != 0)
		return true;

	return false;
}*/
	else if (Year % 100 == 0)
	{
		return false;
	}

	else if (Year % 4 == 0)
	{
		return true;
	}
	else
		return false;
}



int main()
{
	short Year;
	cout << "Enter  Year to check is it Leap Year or not: \n";
	cin >> Year;
	if (IsLeapYear(Year))
		cout << "Yes, The Year [" << Year << "] is Leap." << endl;

	
	else 
	cout << "No, The Year [" << Year << "] is Not Leap." << endl;
}