#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

const string ClintsFileName = "ClintFile.txt";
string Seperator = "#//#";


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
	getline(cin >> ws, ClintData.AccountNumber);

	cout << "Enter  PinCode? \n";
	getline(cin, ClintData.PinCode);

	cout << "Enter Name? \n";
	getline(cin, ClintData.Name);

	cout << "Enter Phone Number?  \n";
	getline(cin, ClintData.PhoneNumber);

	cout << "Enter Account Balance? \n";
	cin >> ClintData.AccountBalance;

	return ClintData;
}


string ConverRecordToLine(stClintData ClintData, string delim)
{
	string S1 = "";
	S1 += ClintData.AccountNumber + delim;
	S1 += ClintData.PinCode + delim;
	S1 += ClintData.Name + delim;
	S1 += ClintData.PhoneNumber + delim;
	S1 += to_string(ClintData.AccountBalance);
	return S1;


}

void AddClintsToFile(string stLine,string FileName)
{
	fstream ClintFile;
	ClintFile.open(FileName, ios::out|ios::app);

	if (ClintFile.is_open())
	{
		ClintFile << stLine << "\n";
		ClintFile.close();
	}
}


void AddClint()
{

	stClintData Clint;
	Clint = ReadClintData();
	AddClintsToFile(ConverRecordToLine(Clint, Seperator), ClintsFileName);

}


void AddClints()
{

	char AddMore='Y';
	do
	{
		system("cls");
		cout << "Adding New Clint:\n";

		AddClint();

		cout << "Do you want to add more clints? (Y,N)?";
		cin >> AddMore;


	} while (toupper( AddMore) == 'Y');
}

int main()
{
	AddClints();

}