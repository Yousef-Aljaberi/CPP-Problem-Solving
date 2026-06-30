#include<iostream>
#include<string>
using namespace std;

struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	double AccountBalance;
};


stClintData ReadClintData()
{
	stClintData ClintData;
	cout << "Enter Account Number? \n";
	getline(cin, ClintData.AccountNumber);
	cout << "Enter  PinCode? \n";
	getline(cin, ClintData.PinCode);
	cout << "Enter Name? \n";
	getline(cin, ClintData.Name);
	cout << "Enter Phone Number?  \n";
	getline(cin, ClintData.PhoneNumber);
	cout << "Enter Account Balance? \n";
	cin>> ClintData.AccountBalance;

	return ClintData;
}

string ConverRecordToLine(stClintData ClintData, string delim)
{
	string S1 = "";
	S1 += ClintData.AccountNumber + delim;
	S1 += ClintData.PinCode + delim;
	S1 += ClintData.Name + delim;
	S1 += ClintData.PhoneNumber + delim;
	S1 +=to_string( ClintData.AccountBalance);
	return S1;


}
int main()
{
	stClintData ClintData;
	ClintData = ReadClintData();

	
	cout<<"\n\nClint Record for saving is: \n"<<ConverRecordToLine(ClintData, "#//#");


}