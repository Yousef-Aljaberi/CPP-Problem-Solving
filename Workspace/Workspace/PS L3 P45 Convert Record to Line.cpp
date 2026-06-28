#include<iostream>
#include<string>
#include"MyLibe.h"

struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	string AccountBalance;
};

string ConverRecordToLine(stClintData ClintData, string delim)
{
	string S1 = "";
	S1 += ClintData.AccountNumber + delim;
	S1 += ClintData.PinCode + delim;
	S1 += ClintData.Name + delim;
	S1 += ClintData.PhoneNumber + delim;
	S1 += ClintData.AccountBalance+".000000";
	return S1;


}
int main()
{
	stClintData ClintData;

	ClintData.AccountNumber = InPut::PrintMessageAndReadText("Enter Account Number? ");
	ClintData.PinCode = InPut::PrintMessageAndReadText("Enter  PinCode? ");
	ClintData.Name = InPut::PrintMessageAndReadText("Enter Name? ");
	ClintData.PhoneNumber = InPut::PrintMessageAndReadText("Enter Phone Number? ");
	ClintData.AccountBalance = InPut::PrintMessageAndReadText("Enter Account Balance? ");

	cout<<"\n\nClint Record for saving is: \n"<<ConverRecordToLine(ClintData, "#//#");


}