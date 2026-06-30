#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	double AccountBalance;
};

vector<string> SplitString(string text, string delim)
{
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = text.find(delim)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		text.erase(0, pos + delim.length());
	}
	if (text != "")
	{
		vString.push_back(text);
	}

	return vString;

}


stClintData ConvertLineDataToRecord(string RecordLine, string seperator)
{
	stClintData Clint;
	vector <string> vClintData;

	vClintData = SplitString(RecordLine, seperator);
	Clint.AccountNumber = vClintData[0];
	Clint.PinCode = vClintData[1];
	Clint.Name = vClintData[2];
	Clint.PhoneNumber = vClintData[3];
	Clint.AccountBalance = stod(vClintData[4]);


	return Clint;
																		
}

void PrintClintData(stClintData Clint)
{
	cout << "\n\nThe following is the extracted clint record:\n";
	cout << "\n Account Number :" << Clint.AccountNumber;
	cout << "\n PinCode	:" << Clint.PinCode;
	cout << "\n Name		:" << Clint.Name;
	cout << "\n Phone Number   :" << Clint.PhoneNumber;
	cout << "\n Account Balance:" << Clint.AccountBalance;
	cout << "\n\n\n\n";

}
int main()
{
	stClintData Clint;

	string seperator = "#//#";
	string RecordLine = "A150#//#1234#//#Yousif Ameen#//#779390894#//#5000.000000";

	cout << "\n\nLine Record is: \n" << RecordLine;

	Clint =ConvertLineDataToRecord(RecordLine, seperator);
	PrintClintData(Clint);





}