#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

const string FileName = "ClintFile.txt";
short NumberOfClints = 0;
const string seperator = "#//#";
struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	double AccountBalance;
};


vector<string> ReadClintsFromFile(string FileName)
{
	vector<string> vLinesOfClintsData;

	fstream ClintFile;
	ClintFile.open(FileName, ios::in);

	if (ClintFile.is_open())
	{
		string Line;

		while (getline(ClintFile, Line))
		{
			vLinesOfClintsData.push_back(Line);
			NumberOfClints++;
		}

		ClintFile.close();
	}
	return vLinesOfClintsData;


}

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

vector<stClintData> ConvertLineDataToRecord( string seperator)
{
	vector<stClintData> Clints;

	vector <string> vClintsData = ReadClintsFromFile(FileName);
	vector <string> vClintDataLine;


	for (int i = 0; i < 3; i++)
	{
		stClintData Clint;

		vClintDataLine = SplitString(vClintsData[i], seperator);

		Clint.AccountNumber = vClintDataLine[0];
		Clint.PinCode = vClintDataLine[1];
		Clint.Name = vClintDataLine[2];
		Clint.PhoneNumber = vClintDataLine[3];
		Clint.AccountBalance = stod(vClintDataLine[4]);

		Clints.push_back(Clint);

	}
	return Clints;

}

void PrintHeader()
{
	cout << "----------------------------------------------------------------------------------------------------------------\n";
	cout << setw(20) << "| Account Number  " << setw(11) << "| Pin Code  |" << setw(50) << " Clint Name  |" << setw(11) << " Phone Number  |" << setw(10) << " Balance  |\n";
	cout << "----------------------------------------------------------------------------------------------------------------\n";

}

void PrintAllClints(vector<stClintData> Clints)
{
	PrintHeader();
	for (stClintData& Clint : Clints)
	{
		cout <<   "| "<< setw(20) << Clint.AccountBalance << " | "  << " | " <<setw(11)<< Clint.PinCode << " | " <<  " | " << setw(50) << Clint.Name << " | " <<  " | " << setw(11) << Clint.PhoneNumber << " | " <<  " | " << setw(10) << Clint.AccountBalance << " | \n";
	}
}


void ShowAllClints()
{
	vector <stClintData> Clints = ConvertLineDataToRecord(seperator);
	PrintAllClints(Clints);

}


int main()
{
	ShowAllClints();
}
