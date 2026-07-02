#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
const string FileName = "ClintFile.txt";

struct stClintData
{
	string Name = "";
	string PinCode;
	string AccountNumber = "";
	string PhoneNumber;
	double AccountBalance;
};
string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "Please enter Account Number?   ";
	cin >> AccountNumber;

	return AccountNumber;
}

vector<string> SplitString(string text, string Seperator= "#//#")
{
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = text.find(Seperator)) != std::string::npos)
	{
		sWord = text.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		text.erase(0, pos + Seperator.length());
	}
	if (text != "")
	{
		vString.push_back(text);
	}

	return vString;

}


stClintData ConvertLineDataToRecord(string RecordLine)
{
	stClintData Clint;
	vector <string> vClintData;

	vClintData = SplitString(RecordLine);
	Clint.AccountNumber = vClintData[0];
	Clint.PinCode = vClintData[1];
	Clint.Name = vClintData[2];
	Clint.PhoneNumber = vClintData[3];
	Clint.AccountBalance = stod(vClintData[4]);


	return Clint;

}

vector <stClintData> LoadClientDataFromFile(string FileName)
{
	vector<stClintData> Clients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClintData Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineDataToRecord(Line);
			Clients.push_back(Client);
		}


		MyFile.close();
	}

	return Clients;
}

void PrintClient(stClintData Client)
{
	cout << "\nThe following are the client details: \n\n";
	cout << "\nAccount Number: " << Client.AccountNumber ;
	cout << "\nPin Code      : " << Client.PinCode ;
	cout << "\nName	      : " << Client.Name ;
	cout << "\nPhone         : " << Client.PhoneNumber;
	cout << "\nAccount Balance:" << Client.AccountBalance;

}

bool FindClientByAccountNumber(stClintData& Client, string sAccountNumber)
{
	vector<stClintData> Clients = LoadClientDataFromFile(FileName);

	for (stClintData C : Clients)
	{
		if (C.AccountNumber == sAccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;

}



int main()
{
	stClintData Client;
	string AccountNumber = ReadClientAccountNumber();
	
	if (FindClientByAccountNumber(Client, AccountNumber))
	{
		PrintClient(Client);

	}
	else
	{
		cout << "\n Client whith Account Number (" << AccountNumber << ") Not Found!\n\n";
	}


}
