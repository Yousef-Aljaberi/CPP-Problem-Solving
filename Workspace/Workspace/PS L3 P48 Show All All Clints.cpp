#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

const string FileName = "ClintFile.txt";
const string seperator = "#//#";
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

vector<stClintData> LoadClientDataFromFile(string FileName)
{
	vector <stClintData> vClints;

	fstream ClintFile;
	ClintFile.open(FileName, ios::in);

	if (ClintFile.is_open())
	{
		string Line;
	
		stClintData Clint;
		while (getline(ClintFile, Line))
		{
			Clint = ConvertLineDataToRecord(Line, seperator);
			vClints.push_back(Clint);


		}

		ClintFile.close();
	}
	return vClints;


}




void PrintClientRecord(stClintData Client)
{
	cout << "| " << left << setw(15) <<Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.PhoneNumber;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintAllClints(vector<stClintData> vClints)
{
	cout << "\n\t\t\t\t\tClient list (" << vClints.size() << ") Client(s)." << endl;
	cout << "\n_________________________________________________________";
	cout << "__________________________________________" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_________________________________________________________";
	cout << "__________________________________________" << endl;

	for (stClintData Clint : vClints)
	{
		PrintClientRecord(Clint);
		cout << endl;
	}
}



	




int main()
{
	vector <stClintData> Clints = LoadClientDataFromFile(FileName);
	PrintAllClints(Clints);
}
